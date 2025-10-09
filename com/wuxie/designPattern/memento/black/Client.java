package com.wuxie.designPattern.memento.black;

public class Client {
    public static void main(String[] args) {
        GameRole gameRole = new GameRole();
        gameRole.init();
        Manege manage = new Manege();
        manage.setMemento(gameRole.save());
        System.out.println("------------战斗前-------------");
        gameRole.display();
        System.out.println("------------战斗后-------------");
        gameRole.atack();
        gameRole.display();
        System.out.println("------------恢复后-------------");
        gameRole.resore(manage.getMemento());
        gameRole.display();
    }
}
