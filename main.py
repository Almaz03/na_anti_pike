import requests
from bs4 import BeautifulSoup
import telegram
import datetime
import pytz
import asyncio

bot_token = '6105606954:AAFN3Wv6V1wljInQSvt_ZppIvPk7tmXiFqw'
async def on_ready():
    await print("Sucess")

# функция для получения даты на основе команды пользователя
def get_date(message_text: str) -> str:
    tz = pytz.timezone('Europe/Moscow')
    today = datetime.datetime.now(tz=tz).date()
    if 'завтра' in message_text:
        return str(today + datetime.timedelta(days=1))
    elif 'сегодня' in message_text:
        return str(today)
    elif 'вчера' in message_text:
        return str(today - datetime.timedelta(days=1))
    else:
        weekdays = ['понедельник', 'вторник', 'среду', 'четверг', 'пятницу', 'субботу', 'воскресенье']
        for i, day in enumerate(weekdays):
            if day in message_text:
                days_until_monday = today.weekday()
                return str(today + datetime.timedelta(days=i-days_until_monday))

# функция для определения текущей недели
def get_current_week() -> int:
    start_date = datetime.date(2022, 2, 9)  # дата начала учебного года
    today = datetime.datetime.now().date()
    weeks_since_start = (today - start_date).days // 7
    return weeks_since_start % 4 + 1  # на МАИ 4 недели в расписании

# Получаем HTML-код страницы с расписанием на нужную дату
current_week = get_current_week()
group_url = f'https://mai.ru/education/studies/schedule/index.php?group=%D0%9C7%D0%9E-108%D0%A1-22&week={current_week}'

response = requests.get(group_url)
html = response.content

# Парсим HTML-код страницы
soup = BeautifulSoup(html, 'html.parser')
table = soup.find('table', {'class': 'schedule_table'})

# Формируем сообщение с расписанием для отправки в Telegram-бот
message = f'Расписание на {datetime.datetime.now(tz=pytz.timezone("Europe/Moscow")).strftime("%d.%m.%Y")}:\n\n'
if table is None:
    message += 'На эту неделю расписание не найдено'
else:
    for row in table.find_all('tr')[1:]:
        columns = row.find_all('td')
        lesson = columns[1].text.strip()
        time = columns[0].text.strip()
        message += f'{time} - {lesson}\n'

# Получаем последнее сообщение в группе
async def get_last_message():
    bot = telegram.Bot(token=bot_token)
    updates = await bot.get_updates()
    last_message = updates[-1].message.text
    return last_message


async def send_schedule():
    last_message = await get_last_message()
    date = get_date(last_message)
    group_url = f'https://mai.ru/education/studies/schedule/index.php?group=%D0%9C7%D0%9E-108%D0%A1-22&date={date}'

    response = requests.get(group_url)
    html = response.content

    soup = BeautifulSoup(html, 'html.parser')
    table = soup.find('table', {'class': 'schedule_table'})

    message = f'Расписание на {date}:\n\n'
    if table is None:
        message += 'На этот день расписание не найдено'
    else:
        for row in table.find_all('tr')[1:]:
            columns = row.find_all('td')
            lesson = columns[1].text.strip()
            time = columns[0].text.strip()
            message += f'{time} - {lesson}\n'


async def main():
    bot = telegram.Bot(token=bot_token)
    last_update_id = None
    while True:
        updates = await bot.get_updates(offset=last_update_id)
        for update in updates:
            last_update_id = update.update_id + 1
            message = update.message.text
            if '/расписание' in message:
                await send_schedule()


if __name__ == '__main__':
    import asyncio
    asyncio.run(main())