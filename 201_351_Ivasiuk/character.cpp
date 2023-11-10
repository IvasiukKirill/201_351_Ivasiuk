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
    temp.hp = ui->hp->text().toInt();
    temp.range = ui->range->value();

    add_to_vector(temp);

    qDebug() << "on_pushButton_3_clicked: Added character. New index:" << currentCharacterIndex;
}



void Character::add_to_vector(pers temp)
{


    characters.append({temp.type, temp.hp, temp.range});
    currentCharacterIndex++;

    clearFields(); // Очистка полей перед отображением следующего персонажа

}




void Character::displayCharacter(int index)
{
    // Здесь вы можете использовать ваш массив персонажей или другие данные
    // для отображения данных текущего персонажа в соответствующих полях формы.

    // Пример:
//    qDebug() << index;
    ui->type->setText(characters[index].type);
    ui->hp->setValue(characters[index].hp);
    ui->range->setValue(characters[index].range);

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
    if (!characters.isEmpty()) {
        if (currentCharacterIndex < characters.size() - 1) {
            clearFields(); // Очистка полей перед отображением следующего персонажа
            currentCharacterIndex++;
            displayCharacter(currentCharacterIndex);
            qDebug() << currentCharacterIndex;
        } else {
            currentCharacterIndex++;
            clearFields();
        }
    }
}

void Character::on_pushButton_clicked()
{
    if (!characters.isEmpty()) {
        if (currentCharacterIndex > 0) {
            clearFields(); // Очистка полей перед отображением предыдущего персонажа
            currentCharacterIndex--;
            displayCharacter(currentCharacterIndex);
        } else {
//            qDebug() << "Это первый персонаж.";
        }
    }
}


