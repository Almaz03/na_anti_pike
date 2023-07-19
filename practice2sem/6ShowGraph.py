import sys
import numpy
import matplotlib.pyplot as plt

def plot_data(filename):
    try:
        # Отображение информации о текущем процессе
        print("Чтение данных из файла:", filename)

        ms = []
        with open(filename, 'r') as f:
            f = f.readlines()
            for i in range(len(f)):
                if i == 0:
                    continue
                ms.append(list(map(float, f[i].rstrip('\n').split(","))))
        ms = numpy.array(ms)

        # Отображение информации о текущем процессе
        print("Построение графика")

        plt.ion()  # Включаем интерактивный режим

        fig = plt.figure()
        ax = fig.add_subplot(111, projection='3d')
        ax.plot(*ms.T, lw=0.5)

        plt.show(block=True)

        # Отображение информации о завершении процесса
        print("График успешно построен")

    except FileNotFoundError:
        print("Файл не найден:", filename)
    except Exception as e:
        print("Произошла ошибка:", str(e))

if __name__ == "__main__":
    if len(sys.argv) > 1:
        filename = sys.argv[1]
        plot_data(filename)
    else:
        print("Необходимо указать название файла в аргументах командной строки.")
