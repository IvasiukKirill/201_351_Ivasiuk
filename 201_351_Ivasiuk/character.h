#ifndef CHARACTER_H
#define CHARACTER_H

#include <QDialog>

namespace Ui {
class Character;
}

class Character : public QDialog
{
    Q_OBJECT

public:
    explicit Character(QWidget *parent = nullptr);
    struct pers{
        // объявление структуры character
        QString type;
        QString hp;
        double range;
        QString checksum;
    };
    ~Character();

private slots:
    void on_pushButton_3_clicked();
    void add_to_vector(pers temp);
    void clearFields();

    void on_pushButton_clicked();

    void on_next_clicked();

private:
    QVector<pers> characters;  // Массив персонажей
    Ui::Character *ui;
    int currentCharacterIndex;
    void displayCharacter(int index);

};

#endif // CHARACTER_H
