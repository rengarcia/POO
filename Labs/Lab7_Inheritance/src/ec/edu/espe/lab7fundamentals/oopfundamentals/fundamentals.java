/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ec.edu.espe.lab7fundamentals.oopfundamentals;
import ec.edu.espe.lab7fundamentals.oopfundamentals.inheritance.Animal;
import ec.edu.espe.lab7fundamentals.oopfundamentals.inheritance.Mammal;

/**
 *
 * @author Andres Garcia
 */
public class fundamentals {
    public static void main( String[] args ){
        
        Animal animal = new Mammal(2, 4, "Lucy");
        animal.print();
        System.out.println(animal);
        
        Mammal mammal = new Mammal(2,4, "Firulais");
        mammal.print();
        
    }
}
