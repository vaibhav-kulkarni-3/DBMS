/*
Problem Statement-Write a program using TCP socket for wired network for following


*/

import java.net.*;
import java.io.*;  

public class Client
{
        public static void main(String args[])throws Exception
        {  
		Socket s=new Socket("localhost",3333);  
	DataInputStream din=new DataInputStream(s.getInputStream());  
	DataOutputStream dout=new DataOutputStream(s.getOutputStream());  
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));  
		  
		String str="",str2="";  
		while(!str.equals("stop"))
		{  
			str2=din.readUTF();  
			System.out.println("Server says: "+str2);  
			str=br.readLine();  
			dout.writeUTF(str);  
			dout.flush();  
		}  
	  
		dout.close();  
		s.close();  
	}
}
