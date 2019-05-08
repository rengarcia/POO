/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ec.edu.espe.lab5aggregation.model;

/**
 *
 * @author Andres Garcia
 */
public class A {
    
    public A(int i){
        b=new B(i+1);
    }
    private  B b;
    private C c;
    private D d;
    
    public B m(){
        return b;
    }
}
