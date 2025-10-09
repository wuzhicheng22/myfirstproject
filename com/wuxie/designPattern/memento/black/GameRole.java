package com.wuxie.designPattern.memento.black;

public class GameRole {
    private int vit;

    private int atk;

    private int def;

    public void init() {
        this.atk = 100;
        this.vit = 100;
        this.def = 100;
    }

    public void atack() {
        this.atk = 1;
        this.vit = 1;
        this.def = 1;
    }

    public GameRoleMemento save() {
        return new GameRoleMemento(this.vit, this.atk, this.def);
    }

    public void resore(Memento memento) {
        GameRoleMemento gameRoleMemento = (GameRoleMemento) memento;
        this.vit = gameRoleMemento.getVit();
        this.atk = gameRoleMemento.getAtk();
        this.def = gameRoleMemento.getDef();
    }

    public void display() {
        System.out.println("血量：" + this.vit);
        System.out.println("攻击：" + this.atk);
        System.out.println("防御：" + this.def);
    }


    private class GameRoleMemento implements Memento {
        private int vit;

        private int atk;

        private int def;

        public GameRoleMemento() {
        }

        public GameRoleMemento(int vit, int atk, int def) {
            this.vit = vit;
            this.atk = atk;
            this.def = def;
        }

        public int getVit() {
            return vit;
        }

        public void setVit(int vit) {
            this.vit = vit;
        }

        public int getAtk() {
            return atk;
        }

        public void setAtk(int atk) {
            this.atk = atk;
        }

        public int getDef() {
            return def;
        }

        public void setDef(int def) {
            this.def = def;
        }
    }


}
