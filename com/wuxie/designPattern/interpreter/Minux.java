package com.wuxie.designPattern.interpreter;

public class Minux extends AbstractExpression {
    private AbstractExpression left;
    private AbstractExpression right;

    public Minux(AbstractExpression left, AbstractExpression right) {
        this.left = left;
        this.right = right;
    }

    @Override
    public int interpreter(MyContext context) {
        return left.interpreter(context) - right.interpreter(context);
    }

    @Override
    public String toString() {
        return "(" + left.toString() + "-" + right.toString() + ")";
    }
}
