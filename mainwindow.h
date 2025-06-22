#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyPressEvent(QKeyEvent *event) override;
private slots:
    void on_pushButton_theme_clicked();
private:
    Ui::MainWindow *ui;
    void appendToDisplay(const QString &text);
    void calculateResult();
    bool isDarkTheme = true;
    void applyDarkTheme();
    void applyLightTheme();
    QString lastOperator;
    QString lastOperand;
    QString lastResult;
};
#endif // MAINWINDOW_H
