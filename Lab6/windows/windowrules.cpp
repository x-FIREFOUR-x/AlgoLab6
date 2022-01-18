#include "windowrules.h"
#include "ui_windowrules.h"
#include "windows/windowsworker.h"

WindowRules::WindowRules(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WindowRules)
{
    ui->setupUi(this);

    float width = ui->graphicsView->width();
    float height = ui->graphicsView->height();

    current_page = 1;
    set_NumberPage();

    setFixedSize(this->width(), this->height());
    ui->graphicsView->setFixedSize(width, height);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QGraphicsScene* scene = new QGraphicsScene;
    ui->graphicsView->setScene(scene);
    scene = nullptr;
    ui->graphicsView->scene()->setSceneRect(0, 0, width, height);

    paint_page_rules();
}

WindowRules::~WindowRules()
{
    delete ui;
}

void WindowRules::on_CloseRuleButton_clicked()
{
    WindowsWorker::close_WindowRules();
    if(WindowsWorker::get_GameWindow() != nullptr)
        WindowsWorker::show_WindowGame();
    else
        WindowsWorker::open_MainWindow();
}


void WindowRules::on_PreviousPageButton_clicked()
{
    if (current_page == 1)
        current_page = amount_page;
    else
        current_page--;
    set_NumberPage();
    paint_page_rules();
}


void WindowRules::on_NextPageButton_2_clicked()
{
    if (current_page == 6)
        current_page = 1;
    else
        current_page++;
    set_NumberPage();
    paint_page_rules();
}

void WindowRules::set_NumberPage()
{
    ui->NumberPage->setText(QString::number(current_page));
}

void WindowRules::paint_page_rules()
{
    QString all_path = path + name_file + QString::number(current_page) + type_file;
    QPixmap image_board(all_path);
    image_board = image_board.scaled(ui->graphicsView->width(), ui->graphicsView->height());
     ui->graphicsView->scene()->setBackgroundBrush(image_board);
}
