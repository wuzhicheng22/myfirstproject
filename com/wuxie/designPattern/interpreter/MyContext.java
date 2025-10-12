package com.wuxie.designPattern.interpreter;

import java.util.HashMap;
import java.util.Map;

public class MyContext {

    private Map<Variable, Integer> map = new HashMap<>();

    public Integer getValue(Variable variable) {
        return map.get(variable);
    }

    public void setValue(Variable variable, Integer value) {
        map.put(variable, value);
    }

}
