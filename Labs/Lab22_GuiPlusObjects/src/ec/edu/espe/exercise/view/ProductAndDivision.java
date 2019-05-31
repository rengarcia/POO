/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ec.edu.espe.exercise.view;

import static ec.edu.espe.exercise.controller.Operations.Multiply;
import static ec.edu.espe.exercise.controller.Operations.Divide;

/**
 *
 * @author Andres Garcia
 */
public class ProductAndDivision {
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        float dividen=100;
        float divisor=0;
        
        System.out.println(Divide(dividen, divisor));
        
        int factor1=5;
        int factor2=-5;
         System.out.println(Multiply(factor1, factor2));
        
    }
    
   
}
