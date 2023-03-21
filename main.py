import requests
from bs4 import BeautifulSoup
import telegram

# Получаем HTML-код страницы с расписанием
group_url = 'https://mai.ru/education/studies/schedule/index.php?group=%D0%9C7%D0%9E-108%D0%A1-22'
response = requests.get(group_url)
html = response.content

# Парсим HTML-код страницы
soup = BeautifulSoup(html, 'html.parser')
table = soup.find('table', {'class': 'schedule_table'})

# Формируем сообщение с расписанием для отправки в Telegram-бот
message = ''
for row in table.find_all('tr')[1:]:
    columns = row.find_all('td')
    lesson = columns[1].text.strip()
    time = columns[0].text.strip()
    message += f'{time} - {lesson}\n'

# Отправляем сообщение в Telegram-бот
bot_token = 'YOUR_BOT_TOKEN'
chat_id = 'YOUR_CHAT_ID'
bot = telegram.Bot(token=bot_token)
bot.send_message(chat_id=chat_id, text=message)