#include "character.h"
#include "ui_character.h"
#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QMessageBox>
#include <QCryptographicHash>

Character::Character(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Character),
    currentCharacterIndex(0)  // начинаем с первого персонажа
{
    ui->setupUi(this);
}

Character::~Character()
{
    delete ui;
}

void Character::on_pushButton_3_clicked()
{
    pers temp;
    temp.type = ui->type->text();
    temp.hp = ui->hp->text();
    temp.range = ui->range->text().toDouble();

    add_to_vector(temp);
}




QString cryptographicSalt = "your_cryptographic_salt";

void Character::add_to_vector(pers temp)
{

    QString dataForChecksum = temp.type + temp.hp + QString::number(temp.range) + cryptographicSalt;
    QByteArray checksum = QCryptographicHash::hash(dataForChecksum.toUtf8(), QCryptographicHash::Sha256);

    characters.append({temp.type, temp.hp, temp.range, checksum.toHex()});
    qDebug() <<   temp.type <<  temp.hp << temp.range << checksum.toHex();
}




void Character::displayCharacter(int index)
{
    // Здесь вы можете использовать ваш массив персонажей или другие данные
    // для отображения данных текущего персонажа в соответствующих полях формы.

    // Пример:
    ui->type->setText(characters[index].type);
    ui->hp->setText(characters[index].hp);
    ui->range->setText(QString::number(characters[index].range));

    // Добавьте свой код для отображения данных персонажа
}


void Character::clearFields()
{
    // Очистка полей ввода для новых данных
    ui->type->clear();
    ui->hp->clear();
    ui->range->clear();
}



void Character::on_next_clicked()
{
    clearFields(); // Очистка полей перед отображением следующего персонажа
    if (!characters.isEmpty()) {
        if (currentCharacterIndex < characters.size() ) {
            currentCharacterIndex++;
            displayCharacter(currentCharacterIndex);
            qDebug() << currentCharacterIndex;
        } else {
            qDebug() << "Это последний персонаж.";
        }
    }
}

void Character::on_pushButton_clicked()
{
    clearFields(); // Очистка полей перед отображением предыдущего персонажа
    if (!characters.isEmpty()) {
        if (currentCharacterIndex > 0) {
            currentCharacterIndex--;
            displayCharacter(currentCharacterIndex);
        } else {
            qDebug() << "Это первый персонаж.";
        }
    }
}


