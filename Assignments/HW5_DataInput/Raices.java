/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package raices;

/**
 *
 * @author andresgarcia
 */
public class Raices {

    private double a;
    private double b;
    private double c;

    public Raices(double a, double b, double c){
        this.a=a;
        this.b=b;
        this.c=c;
    }
    private void getRaices(){
        double x1=(-b+Math.sqrt(getDiscriminante()))/(2*a);
        double x2=(-b-Math.sqrt(getDiscriminante()))/(2*a);
        
        System.out.println("Solución x1");
        System.out.println(x1);
        System.out.println("Solución x2");
        System.out.println(x2);
        
    }
    private void getRaiz(){
        double x=(-b)/(2*a);
        
        System.out.println("Unica solución");
        System.out.println(x);
    }
   private double getDiscriminante(){
        return Math.pow(b,2)-(4*a*c);
}
   
    private boolean haveRoots(){
        return getDiscriminante()>0;
    }
    private boolean haveRoot(){
        return getDiscriminante()==0;
    }
    
    public void calculate(){
        if(haveRoots()){
            getRaices();
        } else if(haveRoot()){
            getRaiz();
        } else{
            System.out.println("No tiene soluciones!");
        }
}
}
