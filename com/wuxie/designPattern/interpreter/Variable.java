package com.wuxie.designPattern.interpreter;

public class Variable extends AbstractExpression {

    private String name;

    public Variable(String name) {
        this.name = name;
    }

    @Override
    public int interpreter(MyContext context) {
        return context.getValue(this);
    }

    @Override
    public String toString() {
        return name;
    }
}
