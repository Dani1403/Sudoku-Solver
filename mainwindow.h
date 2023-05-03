#pragma once

#include <QtWidgets/QMainWindow>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QVector>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include "ui_Sudoku.h"
#include "sudokupuzzle.h"

class Sudoku : public QMainWindow
{
    Q_OBJECT

public:
    Sudoku(QWidget *parent = nullptr);
    void newGame();
    void solve();
    void reset();
    ~Sudoku();

private:
    Ui::SudokuClass ui;
    QGridLayout* m_gridLayout;
    QVector<QLineEdit*> m_lineEdits;
    QVector<QVector<QLabel*>> m_labelGrid;
    QVector<QVector<QLineEdit*>> m_lineEditGrid;
    SudokuPuzzle* m_puzzle;
};
