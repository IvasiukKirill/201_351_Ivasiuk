#include "mainwindow.h"

#include <QApplication>

#include <windows.h>
#include <winbase.h>
// clang-format on

#include <Tlhelp32.h>
#include <process.h>
#include <stdio.h>
#include <string.h>

#include <QApplication>
#include <QCryptographicHash>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include <QPalette>
#include <QProcess>
#include <QString>

typedef unsigned long long QWORD;
const QByteArray HASH = "hWO1tgFcA8cXa6Lg6ivVbHNH8M7EeqBkbOJw2Id9zJU=";

bool isAppPatched() {
    // 1 Определение начала сегмента .text
    QWORD moduleBase = (QWORD)GetModuleHandle(NULL);  // начальный адрес приложения в виртуальной памяти/
    QWORD text_segment_start = moduleBase + 0x1000;  // адрес сегмента .text/
    //  qDebug() << "text_segment_start = " << Qt::hex << text_segment_start;

    // 2 Определение длины сегмента .text
    PIMAGE_DOS_HEADER pIDH = reinterpret_cast<PIMAGE_DOS_HEADER>(moduleBase);
    PIMAGE_NT_HEADERS pINH =
        reinterpret_cast<PIMAGE_NT_HEADERS>(moduleBase + pIDH->e_lfanew);
    QWORD size_of_text = pINH->OptionalHeader.SizeOfCode;  // размер сегмента
        // .text
    //  qDebug() << "size_of_text = " << size_of_text;

    // 3 Подсчет хэша и его шифрование
    QByteArray text_segment_contents =
        QByteArray((char *)text_segment_start, size_of_text);
    QByteArray hash = QCryptographicHash::hash((text_segment_contents),QCryptographicHash::Sha256).toBase64();
    //  qDebug() << "text_segment_contents = " << Qt::hex
    //           << text_segment_contents.first(100);
    qDebug() << "hash = " << hash;

    // 4 Сравнение хэша полученного на прошлых этапах с эталонным
    const QByteArray hash0_base64 = HASH;
    bool checkresult = (hash == hash0_base64);
    qDebug() << "checkresult = " << hash0_base64;

    // 5 Реакция на измененный хэш
    if (!checkresult) {
        QMessageBox::critical(nullptr, "Error", "App has been patched");
        return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

//        if (isAppPatched()){
//            exit(-1);
//        }
    //    if (isDebuggerPresent()){
    //        exit(-1);
    //    }
    w.show();
    return a.exec(), system("taskkill /im DebugProtector.exe /f");
}
