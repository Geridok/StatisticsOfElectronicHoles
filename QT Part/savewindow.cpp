#include "savewindow.h"
#include "ui_savewindow.h"

SaveWindow::SaveWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SaveWindow)
{
    ui->setupUi(this);
}

SaveWindow::SaveWindow(QCustomPlot *F_T,QCustomPlot *n_T, QVector<double> F, QVector<double> T, QVector<double> n, QWidget *parent): QDialog(parent), ui(new Ui::SaveWindow),
    F{F},T{T},n{n}
{
    ui->setupUi(this);

    this->F_T = F_T;
    this->n_T = n_T;
    QCPDocumentObject *plotObjectHandler = new QCPDocumentObject(this);
    ui->pdfTextEdit->document()->documentLayout()->registerHandler(QCPDocumentObject::PlotTextFormat, plotObjectHandler);
    insertGraphics();
}

SaveWindow::~SaveWindow()
{
    delete ui;
}


void SaveWindow::insertGraphics()
{
    QTextCursor cursor = ui->pdfTextEdit->textCursor();

    // insert the current plot at the cursor position. QCPDocumentObject::generatePlotFormat creates a
    // vectorized snapshot of the passed plot (with the specified width and height) which gets inserted
    // into the text document.

    int width = 480;
    int height = 340;
    cursor.insertText(QString(QChar::ObjectReplacementCharacter), QCPDocumentObject::generatePlotFormat(this->F_T, width, height));
    cursor.insertText(QString(QChar::ObjectReplacementCharacter), QCPDocumentObject::generatePlotFormat(this->n_T, width, height));

    ui->pdfTextEdit->setTextCursor(cursor);
}

void SaveWindow::on_saveGraphButtons_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save Graphics", qApp->applicationDirPath(), "*.pdf");
    if (!fileName.isEmpty())
    {
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName(fileName);
        QMargins pageMargins(10, 10, 10, 10);
#if QT_VERSION < QT_VERSION_CHECK(5, 3, 0)
        printer.setFullPage(false);
        printer.setPaperSize(QPrinter::A4);
        printer.setOrientation(QPrinter::Portrait);
        printer.setPageMargins(pageMargins.left(), pageMargins.top(), pageMargins.right(), pageMargins.bottom(), QPrinter::Millimeter);
#else
        QPageLayout pageLayout;
        pageLayout.setMode(QPageLayout::StandardMode);
        pageLayout.setOrientation(QPageLayout::Portrait);
        pageLayout.setPageSize(QPageSize(QPageSize::A4));
        pageLayout.setUnits(QPageLayout::Millimeter);
        pageLayout.setMargins(QMarginsF(pageMargins));
        printer.setPageLayout(pageLayout);
#endif
        ui->pdfTextEdit->document()->setPageSize(printer.pageRect().size());
        ui->pdfTextEdit->document()->print(&printer);
    }
}

void SaveWindow::on_saveToTxtButton_clicked()
{
     QString fileName = QFileDialog::getSaveFileName(this, "Save Graphics", qApp->applicationDirPath(), "*.txt");
     QFile file(fileName);
     if(file.open(QIODevice::WriteOnly | QIODevice::Text)){
         QTextStream txtStream(&file);
         txtStream << "Temperature Fermi-Dirak Number\n";
         for(int i = 0;i < T.size();i++){
             txtStream << T[i] <<"\t"<< F[i]<<"\t"<<n[i]<<"\n";
         }
         file.close();
     }else{
         QMessageBox::critical(this,"File Error","Can't open the file, try again");
     }

}
