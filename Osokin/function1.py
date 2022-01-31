
def printMaxNumber(a,b):
    if a>b:
        print(str(a) + "Больше")
    elif a==b:
        print("Они равны")
    else:
        print(str(b) + "Больше")
while True:
    try:
        a=int(input("Введите первое число: "))
        b=int(input("Введите второе число: "))
    except ValueError:
            print("Вы ввели не число. Повторите ввод")

    printMaxNumber(a,b)
