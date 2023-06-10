def main():
    n = int(input())
    water_stations = [i * 5 for i in range(22)]
    print(min(water_stations, key=lambda x: abs(x - n)))

if __name__ == '__main__':
    main()