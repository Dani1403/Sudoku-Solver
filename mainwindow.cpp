#include "mainwindow.h"

Sudoku::Sudoku(QWidget* parent)
    : QMainWindow(parent), m_puzzle(new SudokuPuzzle())
{
    ui.setupUi(this);
    m_gridLayout = new QGridLayout();
    m_gridLayout->setSpacing(0);
    m_labelGrid.resize(GRID_SIZE);
    m_lineEditGrid.resize(GRID_SIZE);
    for (int row = 0; row < GRID_SIZE; row++)
    {
        m_labelGrid[row].resize(GRID_SIZE);
        m_lineEditGrid[row].resize(GRID_SIZE);
        for (int col = 0; col < GRID_SIZE; col++)
        {
            QLineEdit* lineEdit = new QLineEdit();
            lineEdit->setAlignment(Qt::AlignCenter);
            lineEdit->setFixedSize(80, 80);
            QLabel* label = new QLabel();
            label->setAlignment(Qt::AlignCenter);
            label->setFixedSize(80, 80);
            label->setStyleSheet("QLabel { border: 1px solid black}");
            m_gridLayout->addWidget(lineEdit, row, col);
            m_gridLayout->addWidget(label, row, col);
            m_lineEdits.append(lineEdit);
            m_labelGrid[row][col] = label;
            m_lineEditGrid[row][col] = lineEdit;
            
            if (row % GROUP_SIZE == 0) 
            {
                if (col % GROUP_SIZE == 0) 
                {
                    label->setStyleSheet("QLabel { border: 1px solid black; border-top: 3px solid black; border-left: 3px solid black}");
                }
                else 
                {
                    label->setStyleSheet("QLabel { border: 1px solid black; border-top: 3px solid black}");
                }
            }
            else 
            {
                if (col % GROUP_SIZE == 0) 
                {
                    label->setStyleSheet("QLabel { border: 1px solid black; border-left: 3px solid black}");
                }
            }

            if (row == GRID_SIZE - 1) 
            {
                if (col % GROUP_SIZE == 0) 
                {
                    label->setStyleSheet("QLabel { border: 1px solid black; border-bottom: 3px solid black; border-left: 3px solid black}");
                }
                else 
                {
                    label->setStyleSheet("QLabel { border: 1px solid black; border-bottom: 3px solid black}");
                }
            }
            else if (col == GRID_SIZE - 1) 
            {
                label->setStyleSheet("QLabel { border: 1px solid black; border-right: 3px solid black}");
            }
            if (row == GRID_SIZE - 1 && col == GRID_SIZE - 1)
            {
                label->setStyleSheet("QLabel { border: 1px solid black; border-bottom: 3px solid black; border-right: 3px solid black}");
            }
            if (row % GROUP_SIZE == 0 && col == GRID_SIZE - 1)
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
    this->update();
}

void Sudoku::solve()
{
	m_puzzle->solvePuzzle(false);
    this->update();

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
    this->update();
}

void Sudoku::update()
{
    for (int row = 0; row < GRID_SIZE; row++)
    {
        for (int col = 0; col < GRID_SIZE; col++)
        {
			QLineEdit* lineEdit = m_lineEditGrid[row][col];
			QLabel* label = m_labelGrid[row][col];
			int value = m_puzzle->getValue(row, col);
            if (value == 0)
            {
				lineEdit->setText("");
				lineEdit->setReadOnly(false);
				lineEdit->setStyleSheet("");
			}
            else
            {
				lineEdit->setText(QString::number(value));
                //change the size of the font
                QFont font = lineEdit->font();
                font.setPointSize(20);
                lineEdit->setFont(font);
				lineEdit->setReadOnly(true);
				lineEdit->setStyleSheet("QLineEdit { color: blue }");
			}
		}
	}
}
