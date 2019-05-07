/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ec.edu.espe.lab7fundamentals.oopfundamentals.inheritance;

/**
 *
 * @author Andres Garcia
 */
public abstract class Animal {
    
    private int numberOfLegs;
    private String name;

    
        public void print(){
            
        System.out.println
        ("name of the class--> "
                +Animal.class + "\nAnimal name is--> " + name 
                + " has " + numberOfLegs + " legs");
        
    }
        @Override
        public String toString(){
            
        String data;
        data="{\"name\": "+name+", \"numberOfLegs\": " +numberOfLegs+ "}";
               
        return data;
        
        }
        
        public Animal(int numberOfLegs, String name) {
            
        this.numberOfLegs = numberOfLegs;
        this.name = name;
        
    }
        public Animal(){
            
        this.numberOfLegs=0;
        
    }
        
      
    /**
     * @return the numberOfLegs
     */
    public int getNumberOfLegs() {
        
        return numberOfLegs;
        
    }

    /**
     * @param numberOfLegs the numberOfLegs to set
     */
    public void setNumberOfLegs(int numberOfLegs) {
        
        this.numberOfLegs = numberOfLegs;
        
    }

    /**
     * @return the name
     */
    public String getName() {
        
        return name;
        
    }

    /**
     * @param name the name to set
     */
    public void setName(String name) {
        
        this.name = name;
        
    }



    
}
