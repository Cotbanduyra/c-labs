#include "forlab10.h"


namespace {

bool EliminateColumn(int i, int n, double** a, double** b);

void EliminateRow(int k, int i, int n, double** a, double** b) {
    double factor = a[k][i];
    for (int j = 0; j < n; j++) {
        a[k][j] -= factor * a[i][j];
        b[k][j] -= factor * b[i][j];
    }
}

bool EliminateColumn(int i, int n, double** a, double** b) {
    double pivot = a[i][i];
    int pivotRow = i;
    for (int k = i + 1; k < n; k++) {
        double v = a[k][i] < 0 ? -a[k][i] : a[k][i];
        double p = pivot < 0 ? -pivot : pivot;
        if (v > p) { pivot = a[k][i]; pivotRow = k; }
    }
    if (pivot < 0 ? -pivot < 1e-9 : pivot < 1e-9)
        return false;

    if (pivotRow != i) {
        std::swap(a[i], a[pivotRow]);
        std::swap(b[i], b[pivotRow]);
    }
    double div = a[i][i];
    for (int j = 0; j < n; j++) { a[i][j] /= div; b[i][j] /= div; }

    for (int k = 0; k < n; k++)
        if (k != i) EliminateRow(k, i, n, a, b);
    return true;
}
}

Matrix::Matrix() : rows(0), cols(0), matrix(nullptr) {}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    matrix = new Vector[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = Vector(cols);
}

Matrix::Matrix(int val) : rows(1), cols(1) {
    matrix = new Vector[1];
    matrix[0] = Vector(1);
    matrix[0][0] = val;
}

Matrix::Matrix(Matrix&& other) noexcept
    : rows(other.rows), cols(other.cols), matrix(other.matrix) {
    other.matrix = nullptr;
    other.rows = 0;
    other.cols = 0;
}

Matrix::Matrix(const Matrix& other, int gap) : rows(other.rows), cols(other.cols) {
    matrix = new Vector[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = Vector(cols);
        for (int j = 0; j < cols; j++)
            matrix[i][j] = other.matrix[i][j] + gap;
    }
}

Matrix::~Matrix() {
    delete [] matrix;
}

int Matrix::GetCols() const { return cols;}
int Matrix::GetRows() const { return rows;}
mat Matrix::GetMat() const  { return matrix;}

///////////////////// OPERATORS //////////////

///*
Matrix& Matrix::operator= (const Matrix& other){
    if (this != &other) {
        mat newMat = new Vector[other.rows];
        for (int i = 0; i < other.rows; i++) {
            newMat[i] = Vector(other.cols);
            for (int j = 0; j < other.cols; j++)
                newMat[i][j] = other.matrix[i][j];
        }
        delete[] matrix;
        matrix = newMat;
        this->cols = other.GetCols();
        this->rows = other.GetRows();
    }
    return *this;
}

Matrix& Matrix::operator= (Matrix&& other) noexcept { 
     if (this != &other) {
        delete[] matrix;
        matrix = other.matrix;
        rows = other.rows;
        cols = other.cols;
        other.matrix = nullptr;
        other.rows = 0;
        other.cols = 0;
    }
    return *this;
}

Vector& Matrix::operator[] (size_t idx){
    return matrix[idx];
}

Vector const& Matrix::operator[] (size_t idx) const{
    return matrix[idx];
}

Matrix operator+ (const Matrix& first, const Matrix& second){
 if (first.rows != second.rows || first.cols != second.cols)
        throw std::invalid_argument("Diff dims");

    Matrix res(first.rows, first.cols);
    for (int i = 0; i < first.rows; i++)
        for (int j = 0; j < first.cols; j++)
            res[i][j] = first[i][j] + second[i][j];
    return res;
}
Matrix operator- (const Matrix& first, const Matrix& second) {
    if (first.rows != second.rows || first.cols != second.cols)
        throw std::invalid_argument("Diff dims");

    Matrix res(first.rows, first.cols);
    for (int i = 0; i < first.rows; i++)
        for (int j = 0; j < first.cols; j++)
            res[i][j] = first[i][j] - second[i][j];
    return res;
}

Matrix operator* (const Matrix& first, const Matrix& second){
    if (first.cols != second.rows)
        throw std::runtime_error("first cols != second rows");

    Matrix temp(first.rows, second.cols);
    for (int i = 0; i < first.rows; i++)
        for (int j = 0; j < second.cols; j++) {
            int sum = 0;
            for (int k = 0; k < first.cols; k++)
                sum += first.matrix[i][k] * second.matrix[k][j];
            temp.matrix[i][j] = sum;
        }
    return temp;
}

Matrix& Matrix::operator+= (const int& k){
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            (*this)[i][j] += k;
    return *this;
}

Matrix& Matrix::operator-= (const int& k){
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            (*this)[i][j] -= k;
    return *this;
}

Matrix& Matrix::operator*= (const int& k){
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            (*this)[i][j] *= k;
    return *this;
}

Matrix& Matrix::operator+= (const Matrix& k){
    if (rows == k.rows && cols == k.cols)
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            (*this)[i][j] += k[i][j];
    return *this;
}

Matrix& Matrix::operator-= (const Matrix& k){
    if (rows == k.rows && cols == k.cols)
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            (*this)[i][j] -= k[i][j];
    return *this;
}

Matrix& Matrix::operator*= (const Matrix& k){
    if (rows == k.rows && cols == k.cols)
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            (*this)[i][j] *= k[i][j];
    return *this;
}

bool operator== (const Matrix& first, const Matrix& second) {
    bool res = true;
    if (&first != &second) {
        if (first.rows == second.rows && first.cols == second.cols) {
            for (int i = 0; i < first.rows && res; i++)
                for (int j = 0; j < first.cols && res; j++)
                    if (first[i][j] != second[i][j]) res = false;
        }
        else res = false;
    }
    return res;
}

bool operator!= (const Matrix& first, const Matrix& second) {
    bool res = true;
    if (&first == &second) res = false;
    else
    if (first.rows == second.rows && first.cols == second.cols)
        for (int i = 0; i < first.rows && res; i++)
            for (int j = 0; j < first.cols && res; j++)
                if (first[i][j] == second[i][j]) res = false;
    return res;
}

bool operator> (const Matrix& first, const Matrix& second) {
    bool res = true;
    if (first.rows != second.rows || first.cols != second.cols)
        res = false;
    else
        for (int i = 0; i < first.rows && res; i++)
            for (int j = 0; j < first.cols && res; j++)
                if (first[i][j] <= second[i][j])
                    res = false;
    return res;
}

bool operator< (const Matrix& first, const Matrix& second) {
    bool res = true;
    if (first.rows != second.rows || first.cols != second.cols)
        res = false;
    else
        for (int i = 0; i < first.rows && res; i++)
            for (int j = 0; j < first.cols && res; j++)
                if (first[i][j] >= second[i][j])
                    res = false;
    return res;
}

bool operator<= (const Matrix& first, const Matrix& second) {
    return !(first > second);
}

bool operator>= (const Matrix& first, const Matrix& second) {
    return !(first < second);
}

//zahita

Matrix Matrix::operator~() const{
    bool ok = true;
    if (rows != cols) throw std::runtime_error("Not square for invert");
    if (rows == 0)    throw std::runtime_error("Empty Matrix");

    int n = rows;
    Matrix res(*this);

    double** a = new double*[n];
    double** b = new double*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new double[n];
        b[i] = new double[n]();
        for (int j = 0; j < n; j++) a[i][j] = res[i][j];
        b[i][i] = 1.0;
    }

    for (int i = 0; i < n && ok; i++)
        ok = EliminateColumn(i, n, a, b);
    
    if (ok) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res[i][j] =
                    (int)(b[i][j] < 0 ? b[i][j] - 0.5 : b[i][j] + 0.5);
    }

    for (int i = 0; i < n; i++) { delete[] a[i]; delete[] b[i]; }
    delete[] a; delete[] b;

    return res;
}


/////////////////////////////

std::ostream& operator<< (std::ostream& os, const Matrix& obj){
    os << obj.rows << "x" << obj.cols << '\n';
    for (int i = 0; i < obj.rows; i++){
        for (int j = 0; j < obj.cols; j++){
            os << obj[i][j] << " "; 
        }
        os << "\n";
    }
    os << std::endl;
    return os;
}

std::istream& operator>> (std::istream& is, Matrix& obj){
    std::cout << "Enter element of matrix " << obj.rows << 'x' << obj.cols << ": ";
    for (int i = 0; i < obj.rows; i++) {
        for (int j = 0; j < obj.cols; j++) {
            is >> obj[i][j];
        }
    }
    return is;
}
//*/