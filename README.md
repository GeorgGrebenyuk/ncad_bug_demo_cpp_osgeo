# ncad_bug_demo_cpp_osgeo
Пример исходного кода двух проектов (.NET API и C++ CLI; NRX) под платформу nanoCAD 23 с проблемой неработоспособности на новых версия Windows 10

## Краткое описание идеи

Плагин разрабатывается под расширение фукциональных возможностей платформы nanoCAD для работы с гео-данными за счёт мощного пакета вспомогательных библиотек OSGeo GDAL (инструменты работы с растрами, векторами, системами координат). https://www.osgeo.org/projects/gdal/.

## Описание настройки системы

1. Загружаем стабильную сборку OSGeo SDK release-1930-x64-dev (https://www.gisinternals.com/sdk.php);
2. Создаем системную переменную под загруженный SDK в виде пути к первой вложенной папке `E:\30_Coding\SDK\release-1930-x64-dev\release-1930-x64` (так, чтобы каталог содержал конечные папки с файлами библиотек);
3. В корне диска С размещаем файл из папки examples `bicycles.geojson`;

## Описание логики проектов

В папке `src` лежит файл решения `osgeo_example.sln` (MS Visual Studio 2022) в составе 4 проектов:

- `nrx_osgeo_example`: библиотека классов MFC Dynamic DLL использующая оригинальный C++ API OSGeo, компилируется в NRX `nrx_osgeo_example.nrx` для загрузки в nanoCAD, команда `OGR_RUN_CPP`;
- `osgeo_net_wrapper`: библиотека классов C++ CLI над оригинальным C++ API OSGeo под целевое использование на .NET 6.0;
- `net_osgeo_example`: библиотека классов на .NET 6.0 использующая `osgeo_net_wrapper`, компилируется в .NET DLL `net_osgeo_example.dll` для загрузки в nanoCAD, команда `OGR_RUN_NET`;
- `console_net_osgeo_example`: консольное приложение на .NET 6.0 использующая `osgeo_net_wrapper` для тестирования работы утилиты вне nanoCAD;

Копирование библиотек OSGeo происходит в рамках Post-build events у проекта "osgeo_net_wrapper"

Скомпилированные проекты в режиме Release расположены в Релизах репозитория -- https://github.com/GeorgGrebenyuk/ncad_bug_demo_cpp_osgeo/releases/tag/rel_1.0.

# Ошибки

На новых версиях Windows при попытке загрузки NRX выскочит ошибка подобного рода:

> APPLOAD,ЗАГПРИЛ - Загрузка приложения...Не удается загрузить модуль "C:\Users\Georg\Documents\tbs_gis\Release\nrx_osgeo_example.nrx", ошибка: Не найдена указанная процедура.

При исполнении .NET плагина также будет "вольная ошибка" (показывающая проблемы поиска зависимостей для CLI-библиотеки)

> Ошибка во время выполнения команды: 'Could not load file or assembly 'osgeo_net_wrapper, Version=1.0.8507.28879, Culture=neutral, PublicKeyToken=null'. Не удается найти указанный файл.'.

## Детальная информация о версиях:

Версия nanoCAD 23.0.6140.4113 на тестировавшихся машинах (сборка 6247)

Эти сборки норм

-Windows 10 Pro 21H2 19044.1889;
-Windows 10 Pro 21H2 19044.1645;
-Windows 10 Pro 22H2 19045.2130;

Эти сборки нет

-Windows 10 Pro 22H2 19045.2604;
-Windows 10 Pro 22H2 19045.2251 (and with updates to 19045.2604)