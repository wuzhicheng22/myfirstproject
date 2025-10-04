package com.wuxie;

import java.util.List;

public class StudentIteratorImpl implements StudentIterator {

    private List<Student> list;
    private int position;

    StudentIteratorImpl(List<Student> list, int size) {
        this.list = list;
        this.position = size - 1;
    }


    @Override
    public boolean hasNext() {
        return position > -1;
    }

    @Override
    public Student next() {
        Student current = list.get(position);
        position--;
        return current;
    }
}
