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
public class TestingExceptions {
    public static void main(String[] args) {
        Animal animal = null;
        
        try{
        System.out.println("the animal eyes ar --> " + animal.Eyes);
        }
        catch(Exception ex){
            System.out.println("Don´t have animals in the system talk with the "
                    + "admin and tell the problem " + ex.getMessage());
        }
}
}
