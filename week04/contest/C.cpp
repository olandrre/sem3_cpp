struct Expression {
    virtual double evaluate() const = 0;

    virtual ~Expression() {}
};

struct Number : Expression {
    Number(double value) : value(value) {}

    double evaluate() const override {
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression {
    BinaryOperation(Expression const *left, char op, Expression const *right) : left(left), right(right), op(op) {}
    double evaluate() const override {
        if (op == '+') return left->evaluate() + right->evaluate();
        if (op == '-') return left->evaluate() - right->evaluate();
        if (op == '*') return left->evaluate() * right->evaluate();
        if (op == '/') return left->evaluate() / right->evaluate();

        return 0.0;
    }

    ~BinaryOperation() {
        delete left;
        delete right;
    }

private:
    Expression const *left;
    Expression const *right;
    char op;
};

int main() {
    return 0;
}