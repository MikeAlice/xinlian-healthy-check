package com.zeroone.star.term.common;

public class OrgStructureException extends RuntimeException{
    public final static Integer CODE = 10110;

    private String message;

    public OrgStructureException(String message) {
        super(message);
        this.message = message;
    }
}
