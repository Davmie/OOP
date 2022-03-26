#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "action_manager.h"
#include "error_handler.h"
#include "operations.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    request_t req;
    req.a = INIT;
    action_manager(&req);
}

MainWindow::~MainWindow()
{
    delete ui;
}

errors draw_action(Ui::MainWindow* ui)
{
    canvas_t ca;

    ca.gV = ui->graphicsView;
    ca.h = ui->graphicsView->height();
    ca.w = ui->graphicsView->width();

    request_t req;
    req.a = DRAW;
    req.ca = ca;

    errors err = action_manager(&req);
    return err;
}

errors transform_and_show(request_t req, Ui::MainWindow* ui)
{
    errors err = action_manager(&req);
    if (err)
        return err;
    else
        err = draw_action(ui);

    return err;
}

// Load figure
void MainWindow::on_actionOpen_triggered()
{
    request_t req;
    req.a = LOAD_FILE;
    req.load_f = "/Users/dmitriy/Downloads/bmstu_OOP-master/lab1/cube.txt";

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

// Transformation
void MainWindow::on_button_Move_clicked()
{
    request_t req;
    req.a = MOVE;

    req.mo.dx = ui->lineEdit_MoveX->text().toInt();
    req.mo.dy = ui->lineEdit_MoveY->text().toInt();
    req.mo.dz = ui->lineEdit_MoveZ->text().toInt();

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_button_Scale_clicked()
{
    request_t req;
    req.a = SCALE;

    req.sc.kx = ui->lineEdit_ScaleX->text().toFloat();
    req.sc.ky = ui->lineEdit_ScaleY->text().toFloat();
    req.sc.kz = ui->lineEdit_ScaleZ->text().toFloat();

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_button_Turn_clicked()
{
    request_t req;
    req.a = TURN;

    req.tu.ox = ui->lineEdit_TurnX->text().toFloat();
    req.tu.oy = ui->lineEdit_TurnY->text().toFloat();
    req.tu.oz = ui->lineEdit_TurnZ->text().toFloat();

    errors err = transform_and_show(req, ui);
    if (err)
        error_message(err);
}

void MainWindow::on_button_Turn_released()
{

}
