#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void control(int num_of_relations,int num,char arr1[18],char arr2[18],char arr3[18]){
	int counter2=0,counter3=0;  //the counters variables I use for my transactions
	int counter10=0,counter11=0,counter12=0;
	fstream file2;                                       //the file pointer I use to write        
	file2.open("exampleoutput.txt",ios::app);            //I open the file in additive mode

	if(!file2.is_open()){                              //Checking whether the file is opened      
		cout<<"The file hasn't opened."<<endl;
		exit(0);
	}
	file2<<num<<endl;                                 //I'm writing the number of relations
///////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	/*Checking for errors in the relations*/
	/*If any of the variables in the relations does not match a variable in the relation set, 
	an error message is written to the file for that relation and the process continues for the other relations.*/
	for(int i=0;i<num;i++){            
		counter10=0;
		counter11=0;
		for(int j=0;j<num_of_relations;j++){     
			if(arr1[i]==arr3[j]){     //if the first variable in the relations matches an element in the relation set, the counter increments by one.
				counter10++;          
			}
			if(arr2[i]==arr3[j]){     //If the second variable in the relations matches an element in the correlation set, the counter increments by one.
				counter11++;
			}}		
		if(counter10==0){       //If the counter remains at 0, it means that the first element in the relations does not match any element in the set. 
			file2<<"The element "<<arr1[i]<<" of the relation ("<<arr1[i]<<", "<<arr2[i]<<") is not found in the set A = {";
			for(int k=0;k<num_of_relations;k++){
				file2<<arr3[k];
				if(k!=num_of_relations-1){
					file2<<", ";
				}}
			file2<<"}.";	
			counter12++;  //I increased this counter because there was an error in the relation. Thus, REFLEXIVE, SYMMETRİC, ANSYMMETRİC AND TRANSITİVE operations will not be checked.
			file2<<endl;
			break;
		}
		if(counter11==0){     //If the counter remains at 0, it means that the second element in the relations does not match any element in the set. 
			file2<<"The element "<<arr2[i]<<" of the relation ("<<arr1[i]<<", "<<arr2[i]<<") is not found in the set A = {";
			for(int k=0;k<num_of_relations;k++){
				file2<<arr3[k];
				if(k!=num_of_relations-1){
					file2<<", ";
				}}
			file2<<"}.";
			counter12++;  //I increased this counter because there was an error in the relation. Thus, REFLEXIVE, SYMMETRİC, ANSYMMETRİC AND TRANSITİVE operations will not be checked.
			file2<<endl;
			break;
		}}
		

///////////////////////////////////////////////////////////////////////////////////////////////////////////////		
	if(counter12==0){    //It means that the counter is 0, there is no error in the relation.
		//REFLEXIVE
		/* Elements in the relation set are checked one by one.
		If both variables in the relation match an element in the set, then we are close to the reflexive condition. 
		If the number of matches is equal to the number of elements in the set, this means that the relation set becomes reflexive.	*/
		int k=num;
		for(int j=0;j<num_of_relations;j++){    //I check the relations one by one.
			counter2=0;  
			for(int i=0;i<num;i++){              //A check for the number of elements in the relation set.    
				if(arr3[j]==arr1[i] && arr3[j]==arr2[i]){
					counter2++;        //If an element in the relation set has a pair, the counter increases.
				}
				if(i==num-1){			//if the loop has come to an end
					if(counter2==0){    //counter not incremented means that one of the elements in the relation set has no pair
						arr1[k]=arr3[j];    //for the relation set element which has not a pair in the relations, 
						arr2[k]=arr3[j];		 //i add the its pair at the end of the my arrays
						k++;
					}}}}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
		int hold1[18];  //my hold array that holds some relations for the broke symmetric situations and draw hasse diagram
		int index=0;   //hold array index

		//SYMMETRİC AND ANSYMMETRİC
		/*We have two relations.
		If the first element in the first relation matches the second element in the second relation, 
		and the first element of the second relation matches the second element in the first relation, 
		one of the symmetric conditions is satisfied. This is true for the whole set of relations.
		This relation cannot be ansymmetric if even one of the symmetric conditions is satisfied.*/

		for(int i=0;i<num;i++){   // it's check as many relations in R
			for(int j=i;j<num;j++){         //it's check as many relations in R
				if(arr1[i]==arr2[j] && arr2[i]==arr1[j]){    //Symmetric checks are done one by one for any two relations.     
					if(arr1[j]!=arr2[j]){          //if the relation determined does not have the same element
						hold1[index]=j;             //I'm assigning the index of one of the elements providing symmetry to an array.
						index++;
					}}}}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		int h=index;          //I keep the last index value in an element.
		num=k;                 //We added new relations to provide poset, so the number of existing relations changed.
								// I assigned the last sum of relations to an element.
		//TRANSİTİVE
		for(int i=0;i<num;i++){        //one loop as many relations.
			counter3=0;
			counter2=0;
			/*We assigned the index of one of the conditions that provide symmetry to an array.
			I kept a counter to skip this index in the transitive control.
			If the counter increases, no action will be taken for the relation we have extracted from the relation set.*/
			for(int p=0;p<h;p++){
				if(i==hold1[p]){
					counter2++;
				}}
			for(int j=0;j<num;j++){      //one loop as many relations.   
				if(arr1[i]!=arr2[i]){	//A condition for relation cases that do not have identical elements.
					if(arr2[i]==arr1[j]){	   //if the second element of any relation state (first relation state) and the first element of another relation state (second relation state) match,
						/*No control is made for one of the situations that provides symmetry again.*/
						for(int p=0;p<h;p++){
							if(j==hold1[p]){
								counter2++;
							}}

						if(arr1[j]!=arr2[j]){        //If the second relation state does not have identical elements,
							for(int t=0;t<num;t++){        //one loop as many relations.    
								//Our counter has not increased, so we are not in the relation that provides symmetry. We can do our control.
								if(counter2==0){
									if(arr1[t]==arr1[i] && arr2[t]==arr2[j]){       //If the first element of the first relation and the second element of the second relation are the same as any relation state (third relation state),
									//If the relation providing the transitive property is found in the set of relations, the counter is incremented by one.	
										counter3++;            
										hold1[index]=t;    //I assigned the relation's index providing the transitive property to my hold array.
										index++;
										break;
									}
									if(t==num-1 && counter3==0){  //the counter has not increased and the control has reached the end
									//The relation that does not satisfy the transitive is added to the end of our relation set.	
										arr1[k]=arr1[i];          
										arr2[k]=arr2[j];
										k++;
										num++;
									}}}}}}}}
		file2<<"POSET: ";
		for(int i=0;i<k;i++){     //to the end of the relations
			counter2=0;
			for(int j=0;j<h;j++){     //One of the relations providing symmetry is not printed on the screen.
				if(i==hold1[j]){
					counter2++;
				}}
			if(counter2!=0){
				continue;
			}
			file2<<" ("<<arr1[i]<<", "<<arr2[i]<<")";//we write the POSET in our file.
		}
		file2<<endl;

		for(int i=0;i<k;i++){   //to the end of the relations
			counter2=0;
			counter3=0;
			//We separate the relations that provide symmetry and provide transitive from our POSET set. 
			//And we write the Hasse diagram in our file.
			for(int j=0;j<index;j++){
				if(i==hold1[j]){
					counter2++;
				}}
			if(arr1[i]==arr2[i]){
				counter3++;
			}
			if(counter2!=0 || counter3!=0){
				continue;
			}	
			file2<<arr1[i]<<","<<arr2[i]<<endl;
		}}
		file2<<endl;	
		file2.close();
}

template <typename T>    //I use it for the variable type of the file pointer in the read_file function.

void read_file(T &file,int &num,int &num_of_relations,string str1,string str2,string str3,char arr1[18],char arr2[18],char arr3[18]){
	num=0;                       //number of relations. n expression.   how many relations in R.
	num_of_relations=0;          //The number of variables in the relation set. 3 for A = {a, b, c}    the elements of the set A.
	
	int ctr=0; 
	file>>str1;                    //I'm reading the relation number from the file       how many relations in R.
	num=(int)str1[0]-48;		   //I converted the relation number from char to integer.
	file>>str2;					   //I'm reading the variables in the relation set.        the elements of the set A.
	
	if(num==1){		      //a check to avoid errors when reading from the file according to different states of the variable number. 
		num=num*10;
	}
	
	arr1[num];        //An array where I store the first variable in the relations. For example (a, b) the a in the relation expression.	
	arr2[num];		  //An array where I store the second variable in the relations. For example (a, b) the b in the relation expression. 
	
	//An algorithm I wrote to find the number of variables in the relation set.
	for(int i=0;i<20;i++){
		if(str2[i]==','){	//One more comma is the number of variables in the relation set.
			ctr++;
		}
		if(str2[i]==' '){  //Seeing the void it exits the for loop.
			break;
		}}
	num_of_relations=ctr+1;   //The number of variables in the relation set. 3 for A = {a, b, c}
	arr3[num_of_relations];   //The array where I hold the variables in the relation set.
	int t=0;                 //index variable for arr3

	for(int i=0;i<20;i++){         //I'm passing the variables in the relation set in the str2 string to arr3.
		if(i==0){
			arr3[t]=str2[i];
			t++;
		}
		if(str2[i]==','){
			arr3[t]=str2[i+1];
			t++;
		}
		if(str2[i]==' '){
			break;
		}}
	for(int i=0;i<num;i++){        //give each relation in R.
		file>>str3;                       //I read the relations of the relation set line by line.
		
		arr1[i]=str3[0];				//I'm storing the first variable in the relations.
		arr2[i]=str3[2];                 ////I'm storing the second variable in the relations.
	} 
}
int main(){
	ifstream file;       //the file opens in read mode.
	file.open("input.txt");

	if(!file.is_open()){                    //dosyanın açılıp açılmadığı kontrol edilir.
		cout<<"The file hasn't opened."<<endl;
		exit(0);
	}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	string str1,str2,str3;   //It is checked whether the file has been opened or not.
	int num=0;                // how many relations in R.
	int num_of_relations=0;    //the elements of the set A
	
	int ctr=0;
	char arr1[18];     //An array where I store the first variable in the relations. For example (a, b) the a in the relation expression.
	char arr2[18];     //An array where I store the second variable in the relations. For example (a, b) the b in the relation expression. 
	char arr3[18];     //The array where I hold the variables in the relation set.
	int t=0;
	
	read_file(file,num,num_of_relations,str1,str2,str3,arr1,arr2,arr3);     //for the relation n=9 
	control(num_of_relations,num,arr1,arr2,arr3);	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	read_file(file,num,num_of_relations,str1,str2,str3,arr1,arr2,arr3);     //for the relation n=8 
	control(num_of_relations,num,arr1,arr2,arr3);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	read_file(file,num,num_of_relations,str1,str2,str3,arr1,arr2,arr3);      //for the relation n=5 
	control(num_of_relations,num,arr1,arr2,arr3);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	read_file(file,num,num_of_relations,str1,str2,str3,arr1,arr2,arr3);       //for the relation n=3 
	control(num_of_relations,num,arr1,arr2,arr3);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	read_file(file,num,num_of_relations,str1,str2,str3,arr1,arr2,arr3);        //for the relation n=7 
	control(num_of_relations,num,arr1,arr2,arr3);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	read_file(file,num,num_of_relations,str1,str2,str3,arr1,arr2,arr3);        //for the relation n=6 
	control(num_of_relations,num,arr1,arr2,arr3);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	read_file(file,num,num_of_relations,str1,str2,str3,arr1,arr2,arr3);        //for the relation n=10 
	control(num_of_relations,num,arr1,arr2,arr3);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	read_file(file,num,num_of_relations,str1,str2,str3,arr1,arr2,arr3);        //for the relation n=8 
	control(num_of_relations,num,arr1,arr2,arr3);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	file.close();

	return 0;
}