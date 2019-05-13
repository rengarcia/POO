/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ec.edu.espe.lab7fundamentals.oopfundamentals;
import ec.edu.espe.lab7fundamentals.oopfundamentals.inheritance.Animal;
import ec.edu.espe.lab7fundamentals.oopfundamentals.inheritance.Lion;
import ec.edu.espe.lab7fundamentals.oopfundamentals.interfaces.Horse;
import ec.edu.espe.lab7fundamentals.oopfundamentals.interfaces.WildAnimal;

/**
 *
 * @author Andres Garcia
 */
public class fundamentals {
    public static void main( String[] args ){
        
     
        
//        Mammal mammal = new Mammal(2,4, "Firulais") {};
//        mammal.print();
        
   //     Animal animal = new Lion(true, true, 3, 4, "Alex");
   //   System.out.println(animal.getData());
   
   WildAnimal wildanimal = new Horse(2);
        System.out.println(wildanimal.run());
   
    }
}
