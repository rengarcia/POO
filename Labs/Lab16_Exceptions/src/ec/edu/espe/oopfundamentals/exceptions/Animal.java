/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ec.edu.espe.oopfundamentals.exceptions;

/**
 *
 * @author Andres Garcia
 */
public class Animal {
    
    public String Eyes;
    
    public void eat() throws RuntimeException{
        
        System.out.println("the animal is eating and its eyes are -->"+ Eyes.toString());
    } 
    
    public String toString(){
        
        return "I am an animal class";
    }
}
