name: Сборка и тестирование

on:
  push:
    branches: [ main ]
  pull_request:
    branches: [ main ]

jobs:
  build:

    runs-on: ubuntu-latest

    steps:
    - uses: actions/checkout@v3  # Клонировать репозиторий
    - name: Установка зависимостей
      run: |
        sudo apt-get update
        sudo apt-get install -y gsed  # Установить gsed
        # Установите другие зависимости, необходимые вашему проекту здесь
        # Пример: sudo apt-get install -y libsdl2-dev

    - name: Изменение файлов (замены gsed)
      run: |
        gsed -i 's/lab04/lab05/g' README.md
        gsed -i 's/\(DCMAKE_INSTALL_PREFIX=_install\)/\1 -DBUILD_TESTS=ON/' .github/workflows/main.yml
        gsed -i '/cmake --build _build --target install/a\- cmake --build _build --target test -- ARGS=--verbose' .github/workflows/main.yml

    - name: Конфигурация CMake
      run: cmake -B _build -DCMAKE_BUILD_TYPE=Release

    - name: Сборка
      run: cmake --build _build

    - name: Тестирование
      run: cmake --build _build --target test -- ARGS=--verbose #Запустить тесты

    - name: Установка
      run: cmake --build _build --target install

    - name: Загрузка артефактов (Необязательно - Скриншоты)
      if: always()  # Запускать всегда, даже если тесты не прошли
      run: |
        sudo apt-get install -y x11-utils  # Для утилиты создания скриншотов
        mkdir artifacts
        sleep 5s  #Подождать немного времени для загрузки графического интерфейса
        xvfb-run --auto-servernum --server-args='-screen 0 640x480x24' gnome-screenshot --file artifacts/screenshot.png
        echo "Скриншот сделан"

    - name: Загрузка артефактов
      if: always()
      uses: actions/upload-artifact@v3
      with:
        name: artifacts
        path: artifacts
