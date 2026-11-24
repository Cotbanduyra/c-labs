#pragma once

class MatrixExceptions{
    public:
    virtual const char* what() const = 0;
};

class IndexOutOfRange : public MatrixExceptions{
    const char* what() const override { return "Try to acsess index out of range";}
};

class WrongDims : public MatrixExceptions{
    const char* what() const override { return "trying to do opeartion over matrixes with wong dims";}
};
