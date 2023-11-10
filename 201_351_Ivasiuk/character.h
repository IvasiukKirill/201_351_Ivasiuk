#ifndef CHARACTER_H
#define CHARACTER_H

#include <QDialog>

namespace Ui {
class Character;
}

class Character : public QDialog
{
    Q_OBJECT
    struct pers{
        // объявление структуры character
        QString type;
        QString hp;
        QString range;
    };
public:
    explicit Character(QWidget *parent = nullptr);
    ~Character();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::Character *ui;
};

#endif // CHARACTER_H
