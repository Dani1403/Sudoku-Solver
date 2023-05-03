#include "mainwindow.h"

Sudoku::Sudoku(QWidget* parent)
    : QMainWindow(parent), m_puzzle(new SudokuPuzzle())
{
    ui.setupUi(this);
    m_gridLayout = new QGridLayout();
    m_gridLayout->setSpacing(0);
    m_labelGrid.resize(GRID_SIZE);
    m_lineEditGrid.resize(GRID_SIZE);
    for (int i = 0; i < GRID_SIZE; i++)
    {
        m_labelGrid[i].resize(GRID_SIZE);
        m_lineEditGrid[i].resize(GRID_SIZE);
        for (int j = 0; j < GRID_SIZE; j++)
        {
            QLineEdit* lineEdit = new QLineEdit();
            lineEdit->setAlignment(Qt::AlignCenter);
            lineEdit->setFixedSize(80, 80);
            QLabel* label = new QLabel();
            label->setAlignment(Qt::AlignCenter);
            label->setFixedSize(80, 80);
            label->setStyleSheet("QLabel { border: 1px solid black}");
            m_gridLayout->addWidget(lineEdit, i, j);
            m_gridLayout->addWidget(label, i, j);
            m_lineEdits.append(lineEdit);
            m_labelGrid[i][j] = label;
            m_lineEditGrid[i][j] = lineEdit;
            
            if (i % GROUP_SIZE == 0) {
                if (j % GROUP_SIZE == 0) {
                    label->setStyleSheet("QLabel { border: 1px solid black; border-top: 3px solid black; border-left: 3px solid black}");
                }
                else {
                    label->setStyleSheet("QLabel { border: 1px solid black; border-top: 3px solid black}");
                }
            }
            else {
                if (j % GROUP_SIZE == 0) {
                    label->setStyleSheet("QLabel { border: 1px solid black; border-left: 3px solid black}");
                }
            }

            if (i == GRID_SIZE - 1) {
                if (j % GROUP_SIZE == 0) {
                    label->setStyleSheet("QLabel { border: 1px solid black; border-bottom: 3px solid black; border-left: 3px solid black}");
                }
                else {
                    label->setStyleSheet("QLabel { border: 1px solid black; border-bottom: 3px solid black}");
                }
            }
            else if (j == GRID_SIZE - 1) {
                label->setStyleSheet("QLabel { border: 1px solid black; border-right: 3px solid black}");
            }
            if (i == GRID_SIZE - 1 && j == GRID_SIZE - 1)
            {
                label->setStyleSheet("QLabel { border: 1px solid black; border-bottom: 3px solid black; border-right: 3px solid black}");
            }
            if (i % GROUP_SIZE == 0 && j == GRID_SIZE - 1)
            {
				label->setStyleSheet("QLabel { border: 1px solid black; border-top: 3px solid black; border-right: 3px solid black}");
			}

		}
	}

    m_gridLayout->setContentsMargins(1, 1, 1, 1);

    QHBoxLayout* buttonLayout = new QHBoxLayout();
    QPushButton* solveButton = new QPushButton("Solve");
    QPushButton* newGameButton = new QPushButton("New Game");
    buttonLayout->addWidget(solveButton);
    buttonLayout->addWidget(newGameButton);

    connect(newGameButton, &QPushButton::clicked, this, &Sudoku::newGame);
    connect(solveButton, &QPushButton::clicked, this, &Sudoku::solve);

    QVBoxLayout* mainLayout = new QVBoxLayout();
    mainLayout->addLayout(buttonLayout);
    mainLayout->addLayout(m_gridLayout);

    QWidget* mainWidget = new QWidget();
    mainWidget->setLayout(mainLayout);
    setCentralWidget(mainWidget);

}

Sudoku::~Sudoku()
{
    delete m_puzzle;
}

void Sudoku::newGame()
{
    m_puzzle->generatePuzzle();
}

void Sudoku::solve()
{
	m_puzzle->solvePuzzle(false);

}

void Sudoku::reset()
{
    for (int row = 0; row < GRID_SIZE; row++)
    {
        for (int col = 0; col < GRID_SIZE; col++)
        {
            QLineEdit* lineEdit = m_lineEditGrid[row][col];
            lineEdit->setText("");
            lineEdit->setReadOnly(false);
            lineEdit->setStyleSheet("");
        }
    }
	m_puzzle->clearGrid();
}
