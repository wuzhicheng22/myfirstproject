package com.wuxie.designPattern.interpreter;

public class Client {
    public static void main(String[] args) {
        Variable a = new Variable("a");
        Variable b = new Variable("b");
        Variable c = new Variable("c");
        Variable d = new Variable("d");
        MyContext context = new MyContext();
        context.setValue(a, 1);
        context.setValue(b, 2);
        context.setValue(c, 3);
        context.setValue(d, 4);
        //a+b-c+d
        AbstractExpression expression = new Plus(a, new Plus(new Minux(b, c), d));
        int result = expression.interpreter(context);
        System.out.println(expression.toString() + "=" + result);
    }
}
