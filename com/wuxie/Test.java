package com.wuxie;

public class Test {
    public static void main(String[] args) {
        StudentAggregateImpl students = new StudentAggregateImpl();
        students.addStudent(new Student("hangman1", 11));
        students.addStudent(new Student("hangman2", 22));
        students.addStudent(new Student("hangman3", 33));
        StudentIterator studentIterator = students.getStudentIterator();
        while (studentIterator.hasNext()) {
            System.out.println(studentIterator.next().toString());
        }
    }
}
