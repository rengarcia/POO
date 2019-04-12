
package agenda;

import java.util.InputMismatchException;
import java.util.Scanner;
import com.csvreader.CsvReader;
import com.csvreader.CsvWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Agenda {

    public static void main(String[] args) {
        
        Scanner sn = new Scanner(System.in);
        Scanner op = new Scanner(System.in);
        String nombre="",telefono="",correo="",telefonob="",newNombre,newTelefono,newCorreo;
        boolean salir = false;
        int opcion; //Guardaremos la opcion del usuario
        List<Usuario> usuarios = new ArrayList<Usuario>();
        while (!salir) {
 
            System.out.println("1. Crear Archivo CSV");
            System.out.println("2. Añadir Datos");
            System.out.println("3. Eliminar Datos");
            System.out.println("4. Actualizar");
            System.out.println("5. Salir");
 
            try {
 
                System.out.println("Escribe una de las opciones");
                opcion = sn.nextInt();
 
                switch (opcion) {
                    case 1:
                        System.out.println("Has seleccionado la opcion 1");
                        System.out.println("Archivo CSV creado con éxito...");
                        ExportarCSV(usuarios);
                        break;
                    case 2:
                        System.out.println("Has seleccionado la opcion 2");
                        System.out.println("Ingrese Nombre");
                        nombre=op.nextLine();
                        System.out.println("Ingrese Telefono");
                        telefono=op.nextLine();
                        System.out.println("Ingrese Correo");
                        correo=op.nextLine();
                        usuarios.add(new Usuario(nombre,telefono,correo));
                        try{
         
           
             CsvWriter  escribirUsuarios = new CsvWriter ("Usuarios.csv");
   
            escribirUsuarios.write("Nombre");
            escribirUsuarios.write("Telefono");
            escribirUsuarios.write("Email");
              escribirUsuarios.endRecord(); 
             for(Usuario user : usuarios) {
                escribirUsuarios.write(user.getNombre());
                escribirUsuarios.write(user.getTelefono());
                escribirUsuarios.write(user.getEmail());
                
                escribirUsuarios.endRecord(); // Deja de escribir en el archivo
            }
            
           // Deja de escribir en el archivo
            // Mientras haya lineas obtenemos los datos del archivo
           
            escribirUsuarios.close();
        
            
        } catch(FileNotFoundException e) {
            e.printStackTrace();
        } catch(IOException e) {
            e.printStackTrace();
        }
     
                        break;
                    case 3:
                        System.out.println("Has seleccionado la opcion 3");
                        System.out.println("Ingrese Telefono");
                        telefonob=op.nextLine();
                       try{
    
            CsvReader leerUsuarios = new CsvReader("Usuarios.csv");
            leerUsuarios.readHeaders();
            List<Usuario> usuarios2 = new ArrayList<Usuario>();
            // Mientras haya lineas obtenemos los datos del archivo
            while(leerUsuarios.readRecord()) {
                nombre = leerUsuarios.get(0);
                telefono = leerUsuarios.get(1);
                correo = leerUsuarios.get(2);
                
                usuarios2.add(new Usuario(nombre, telefono, correo)); // Añade la informacion a la lista
            }
            
            leerUsuarios.close(); // Cierra el archivo
                           for (int i = 0; i < usuarios2.size(); i++) {
                               if(usuarios2.get(i).getTelefono().compareTo(telefonob)==0)
                               {
                                   usuarios2.remove(i);
                               }
                           }
            System.out.println("Eliminado exitósamente");
           CsvWriter  escribirUsuarios = new CsvWriter ("Usuarios.csv");
   
            escribirUsuarios.write("Nombre");
            escribirUsuarios.write("Telefono");
            escribirUsuarios.write("Email");
              escribirUsuarios.endRecord(); 
             for(Usuario user : usuarios2) {
                escribirUsuarios.write(user.getNombre());
                escribirUsuarios.write(user.getTelefono());
                escribirUsuarios.write(user.getEmail());
                
                escribirUsuarios.endRecord(); // Deja de escribir en el archivo
            }
            
           // Deja de escribir en el archivo
            // Mientras haya lineas obtenemos los datos del archivo
           
            escribirUsuarios.close();
            
            // Recorremos la lista y la mostramos en la pantalla
            
            
        } catch(FileNotFoundException e) {
            e.printStackTrace();
        } catch(IOException e) {
            e.printStackTrace();
        } 
                       
                        break;
                    case 4:
                        System.out.println("Has seleccionado la opcion 4");
                                 System.out.println("Ingrese Telefono");
                        telefonob=op.nextLine();
                        System.out.println("Ingrese Nuevo Nombre");
                        newNombre=op.nextLine();
                        System.out.println("Ingrese Nuevo Telefono");
                        newTelefono=op.nextLine();
                        System.out.println("Ingrese Nuevo Correo");
                        newCorreo=op.nextLine();
                       try{
    
            CsvReader leerUsuarios = new CsvReader("Usuarios.csv");
            leerUsuarios.readHeaders();
            List<Usuario> usuarios2 = new ArrayList<Usuario>();
            // Mientras haya lineas obtenemos los datos del archivo
            while(leerUsuarios.readRecord()) {
                nombre = leerUsuarios.get(0);
                telefono = leerUsuarios.get(1);
                correo = leerUsuarios.get(2);
                
                usuarios2.add(new Usuario(nombre, telefono, correo)); // Añade la informacion a la lista
            }
            
            leerUsuarios.close(); // Cierra el archivo
                           for (int i = 0; i < usuarios2.size(); i++) {
                               if(usuarios2.get(i).getNombre().compareTo(telefonob)==0)
                               {
                                   usuarios2.get(i).setNombre(newNombre);
                                   usuarios2.get(i).setTelefono(newTelefono);
                                   usuarios2.get(i).setEmail(newCorreo);
                               }
                           }
            System.out.println("Actualizado exitósamente");
           CsvWriter  escribirUsuarios = new CsvWriter ("Usuarios.csv");
   
            escribirUsuarios.write("Nombre");
            escribirUsuarios.write("Telefono");
            escribirUsuarios.write("Email");
              escribirUsuarios.endRecord(); 
             for(Usuario user : usuarios2) {
                escribirUsuarios.write(user.getNombre());
                escribirUsuarios.write(user.getTelefono());
                escribirUsuarios.write(user.getEmail());
                
                escribirUsuarios.endRecord(); // Deja de escribir en el archivo
            }
            
           // Deja de escribir en el archivo
            // Mientras haya lineas obtenemos los datos del archivo
           
            escribirUsuarios.close();
            
            // Recorremos la lista y la mostramos en la pantalla
            
            
        } catch(FileNotFoundException e) {
            e.printStackTrace();
        } catch(IOException e) {
            e.printStackTrace();
        } 
                        break;
                    case 5:
                        salir = true;
                        break;
                    default:
                        System.out.println("Solo números entre 1 y 5");
                }
            } catch (InputMismatchException e) {
                System.out.println("Debes insertar un número");
                sn.next();
            }
        }
 
    }
 public static void ExportarCSV(List<Usuario> usuarios) {
        String salidaArchivo = "Usuarios.csv"; // Nombre del archivo
        boolean existe = new File(salidaArchivo).exists(); // Verifica si existe
        
        // Si existe un archivo llamado asi lo borra
        if(existe) {
            File archivoUsuarios = new File(salidaArchivo);
            archivoUsuarios.delete();
        }
        
        try {
            // Crea el archivo
            CsvWriter salidaCSV = new CsvWriter(new FileWriter(salidaArchivo, true), ',');
            
            // Datos para identificar las columnas
            salidaCSV.write("Nombre");
            salidaCSV.write("Telefono");
            salidaCSV.write("Email");
            
            salidaCSV.endRecord(); // Deja de escribir en el archivo
            
            // Recorremos la lista y lo insertamos en el archivo
            for(Usuario user : usuarios) {
                salidaCSV.write(user.getNombre());
                salidaCSV.write(user.getTelefono());
                salidaCSV.write(user.getEmail());
                
                salidaCSV.endRecord(); // Deja de escribir en el archivo
            }
            
            salidaCSV.close(); // Cierra el archivo
            
        } catch(IOException e) {
            e.printStackTrace();
        }    
    }
}
