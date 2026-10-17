#include "forlab8.h"

Matrix::Matrix() : rows(0), cols(0) {
    matrix.resize(0);
    return;
}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    matrix.resize(rows);
    for (auto& i : matrix) i.resize(cols);
    return;
}

Matrix::Matrix(int val) : rows(1), cols(1){
    matrix.resize(1);
    matrix[0].resize(1);
    matrix[0][0] = val;
    return;
}

Matrix::Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), matrix(std::move(other.matrix)) { return; }

Matrix::Matrix(const Matrix& other, int gap) : rows(other.rows), cols(other.cols) {
    matrix.resize(rows);
    for(int i = 0; i < rows; i++){
        matrix[i].resize(cols);
        for (int j = 0; j < cols; j++){
            matrix[i][j] = other.matrix[i][j] + gap;
        }
    }
    return;
}

Matrix::Matrix(std::initializer_list<std::initializer_list<int>> init){
    rows = init.size();
    cols = rows > 0 ? init.begin() -> size() : 0;
    for (auto& i : init ){
        if (i.size() != cols) throw std::invalid_argument("Rows have diff leng");
        matrix.push_back(std::vector<int> (i));
    }
}

Matrix::~Matrix() { 
    return;
}

int Matrix::GetCols() const { return cols;}
int Matrix::GetRows() const { return rows;}
mat Matrix::GetMat() const  { return matrix;}

int& Matrix::at(int i, int j) {
    return matrix[i][j];
}
const int& Matrix::at(int i, int j) const {
    return matrix[i][j];
}

void Matrix::FillMatrix(){
    std::cout << "Enter element of matrix " << rows << 'x' << cols << ": ";
    for(auto& i : matrix){
        for (auto& j : i){
            std::cin >> j;
        }
    }
}

Matrix::operator double() const {
    if (rows == 0 || cols == 0)
        throw std::runtime_error("Matrix is empty");
    double sum = 0.0;
    for (const auto& row : matrix)
        for (double v : row)
            sum += v;
    return sum / (rows * cols);
}

Matrix& Matrix::operator= (const Matrix& other){
    if (this != &other){
        this->cols = other.GetCols();
        this->rows = other.GetRows();
        this->matrix = other.GetMat();
    }
    return *this;
}

Matrix& Matrix::operator= (Matrix&& other) noexcept { 
    if (this != &other){
        this->cols = other.cols;
        this->rows = other.rows;
        this->matrix = std::move(other.matrix);
    }
    return *this;
}

std::vector<int>& Matrix::operator[] (size_t idx){
    return matrix[idx];
}

const std::vector<int>& Matrix::operator[] (size_t idx) const{
    return matrix[idx];
}


std::ostream& operator<< (std::ostream& os, const Matrix& obj){
    os << obj.GetRows() << "x" << obj.GetCols() << '\n';
    for (int i = 0; i < obj.GetRows(); i++){
        for (int j = 0; j < obj.GetCols(); j++){
            os << obj.at(i, j) << " "; 
        }
        os << "\n";
    }
    os << std::endl;
    return os;
}