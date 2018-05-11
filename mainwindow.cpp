#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /* For convenience, the layers are separated QSplitter
     * */
//    ui->splitter->setStretchFactor(0,1);
//    ui->splitter->setStretchFactor(1,0);
}

/* The method for adding dynamic buttons
 * */
void MainWindow::on_addButton_clicked()
{
    dynamicButton *button = new dynamicButton(this);  // Create a dynamic button object
    /* Set the text with number of button
     * */
    button->setText("Кнопочка " + QString::number(button->getID()));
    /* Adding a button to the bed with a vertical layout
     * */
    ui->verticalLayout->addWidget(button);
    /* Connect the signal to the slot pressing buttons produce numbers
     * */
    connect(button, SIGNAL(clicked()), this, SLOT(slotGetNumber()));
}

/* Method for the removal of the dynamic on its number buttons
 * */
void MainWindow::on_deleteButton_clicked()
{
    /* Iterates through all elements of the layer, where are dynamic buttons
     * */
    for(int i = 0; i < ui->verticalLayout->count(); i++){
        /* We produce cast layer element in the dynamic button object
         * */
        dynamicButton *button = qobject_cast<dynamicButton*>(ui->verticalLayout->itemAt(i)->widget());
        /* If the button number corresponds to the number that is set to lineEdit,
         * then deletes the button
         * */
        if(button->getID() == ui->lineEdit->text().toInt()){
            button->hide();
            delete button;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


/* SLOT for getting number of buttons.
 * */
void MainWindow::slotGetNumber()
{
    /* To determine the object that caused the signal
     * */
    dynamicButton *button = (dynamicButton*) sender();
    /* Then set the number of buttons in lineEdit,
     * which is contained in the dynamic button
     * */
    ui->lineEdit->setText(QString::number(button->getID()));
    /* That is the key number is set to lineEdit field only
     * when we press one of the dynamic keys,
     * and this number corresponds to the button you pressed
     * */
}
