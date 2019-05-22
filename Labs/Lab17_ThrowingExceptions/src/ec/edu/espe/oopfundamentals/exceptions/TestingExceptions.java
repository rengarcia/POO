/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ec.edu.espe.oopfundamentals.exceptions;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Andres Garcia
 */
public class TestingExceptions {
    public static void main(String[] args) {
        Animal animal = null;
        
        try{
        System.out.println("the animal eyes ar --> " + animal.eyes);
        }
        catch(Exception ex){
            System.err.println("Don´t have animals in the system talk with the "
                    + "admin and tell the problem " + ex.getMessage());
        }
        System.out.println("the first try-catch passed");
        Animal animal2= new Animal();
        animal2.eyes=null;
        try{
             animal2.eat();
        }
       catch(RuntimeException ex){
           System.out.println("this is the stacktrace" );
           ex.printStackTrace();
           System.out.println("The Logger");
           Logger.getLogger(TestingExceptions.class.getName()).log(Level.SEVERE, null, ex+"Renan");
         //  System.out.println(getClass().getClassLoader().getResource("logging.properties"));
           System.out.println(TestingExceptions.class.getClassLoader().getResource("logging.properties"));
       }
        System.out.println("the second try-catch passed");
        
}       
}