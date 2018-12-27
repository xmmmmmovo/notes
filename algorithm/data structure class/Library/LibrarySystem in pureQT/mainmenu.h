#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QString>
#include <QTreeView>
#include <QTextBrowser>
/**
  真正的主窗口
*/
namespace Ui {
class MainMenu;
}

class MainMenu : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();
    void dealLogin(QString); // 处理登录信息

private slots:
    void on_openBookLib_triggered();

    void on_addBook_triggered();

private:
    Ui::MainMenu *ui;
    QString userName;
    QTextBrowser *bookInfo;
    QTreeView *bookTree;

    void init();
    void paintEvent(QPaintEvent *); // 添加背景
};

#endif // MAINMENU_H
