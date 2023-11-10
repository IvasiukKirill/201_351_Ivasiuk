#include "character.h"
#include "ui_character.h"

Character::Character(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Character)
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
    temp.range = ui->range->text();


}

