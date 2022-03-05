#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void control(int num_of_relations,int num,char arr1[10],char arr2[10],char arr3[10]){
	int counter1=0,counter2=0,counter3=0,counter4=0,counter11=0,counter12=0;  //the counters variables I use for my transactions
	int counter5=0,counter6=0,counter7=0,counter8=0,counter9=0,counter10=0;
	fstream file2;                                       //the file pointer I use to write        
	file2.open("exampleoutput.txt",ios::app);            //I open the file in additive mode

	if(!file2.is_open()){                              //Checking whether the file is opened      
		cout<<"The file hasn't opened."<<endl;
		exit(0);
	}
	file2<<num<<endl;                                 //I'm writing the number of relations
	for(int i=0;i<num;i++){
		file2<<"("<<arr1[i]<<","<<arr2[i]<<")";
	}
	file2<<endl;
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
	if(counter12==0){    //It means that the counter is 0, there is no error in the relation.
///////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		//REFLEXIVE
		/* Elements in the relation set are checked one by one.
		If both variables in the relation match an element in the set, then we are close to the reflexive condition. 
		If the number of matches is equal to the number of elements in the set, this means that the relation set becomes reflexive.	*/
		
		for(int j=0;j<num_of_relations;j++){    //I check the relations one by one.
			counter2=0;  
			for(int i=0;i<num;i++){              //A check for the number of elements in the relation set.    
				if(arr3[j]==arr1[i] && arr3[j]==arr2[i]){
					counter1++;
					counter2++;        //If an element in the relation set has a pair, the counter increases.
				}
				if(i==num-1){			//if the loop has come to an end
					if(counter2==0){    //counter not incremented means that one of the elements in the relation set has no pair
						file2<<"Reflexive: No, For "<<arr3[j]<<", "<<"("<<arr3[j]<<","<<arr3[j]<<") does not exist."<<endl;
						counter5++;
						break;
					}}}
			if(counter1==num_of_relations){   //If the match is equal to the number of elements in the relation set, 
				file2<<"Reflexive: Yes, all elements are present."<<endl;
			}
			if(counter5!=0){  //After it is determined that it does not provide reflexive, it exits the loop immediately.
				break;
			}}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
		char m,n,f,l;
		counter5=0;
		counter2=0;
		//SYMMETRİC AND ANSYMMETRİC
		/*We have two relations.
		If the first element in the first relation matches the second element in the second relation, 
		and the first element of the second relation matches the second element in the first relation, 
		one of the symmetric conditions is satisfied. This is true for the whole set of relations.
		This relation cannot be ansymmetric if even one of the symmetric conditions is satisfied.*/

		for(int i=0;i<num;i++){   // it's check as many relations in R
			counter4=0;
			for(int j=0;j<num;j++){         //it's check as many relations in R
				if(arr1[i]==arr2[j] && arr2[i]==arr1[j]){    //Symmetric checks are done one by one for any two relations.     
					if(arr1[j]!=arr2[j]){          //if the relation determined does not have the same element
						counter4++;
						counter6++;    //A counter to detect anymmetric condition.
						if(counter7==0){        //The relation elements in a satisfying state are valid to two char characters.
							m=arr1[i];          //The relation variables are assigned once with a counter in order not to write repeatedly valid situations.
							n=arr2[i];
							counter7++;
						}}
					if(arr1[j]==arr2[j]){    //if the determined relation has two identical elements.
						counter4++;
						if(counter5==0){	//Elements in the relation are assigned to variables for writing to the file.
							m=arr1[i];				
							n=arr2[i];
							f=arr1[i];
							l=arr2[i];
							counter5++;
						}}}
				if(j==num-1){       //f the loop has come to an end.
					if(counter4==0){		//The counter is not incremented because the symmetric condition was not met.
						if(arr1[i]!=arr2[i]){
							f=arr1[i];			//elements that do not valid are assigned to a variables to write to the file.
							l=arr2[i];                        //i'm writing the relation is not valid for Symmetric and its valid reason to the file
							file2<<"Symmetric: No, "<<"("<<arr1[i]<<","<<arr2[i]<<")"<<" is found whereas "<<"("<<arr2[i]<<","<<arr1[i]<<")" <<" is not found."<<endl;
							counter3++;
							break;    //invalid conditional detected, exit the loop
						}}}}
			if(counter3!=0){
				break;
			}
			if(counter3==0 && i==num-1){      // If the loop has reached the end and there is no case not valid in the relation, 
				                              //i'm writing the relation is valid for Symmetric and its valid reason to the file
				file2<<"Symmetric: Yes,"<<"("<<m<<","<<n<<")"<<" is found whereas "<<"("<<n<<","<<m<<")" <<" is found."<<endl;
			}}			
		if(counter6==0){    //The symmetric property is not provided. And if there is no situation that disrupts the ansymmetric in the relation, 
			                //i'm writing the relation is valid for Ansymmetric and its valid reason to the file   
			file2<<"Ansymmetric: Yes, "<<"("<<f<<","<<l<<")"<<" is found whereas "<<"("<<l<<","<<f<<")" <<" is not found."<<endl;
		}	
		if(counter6!=0){     //symmetric property is provided. And if there is a situation that breaks the ansymmetricity in the relation,
							// i'm writing the relation is not valid for Ansymmetric and its valid reason to the file
			file2<<"Ansymmetric: No, "<<"("<<m<<","<<n<<")"<<" is found whereas "<<"("<<n<<","<<m<<")" <<" is found."<<endl;
		}
		counter2=0,counter3=0,counter4=0,counter5=0;
		int counter18=0,counter19=0;
		char c1,c2,c3;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////		
		//TRANSİTİVE
		for(int i=0;i<num;i++){        //one loop as many relations.
			counter5=0;
			
			for(int k=0;k<num;k++){      //satisfies the Transitive if all relations have identical elements. 
				if(arr1[k]==arr2[k]){
					counter5++;
				}}
			for(int j=0;j<num;j++){      //one loop as many relations.   
				if(arr1[i]!=arr2[i]){	//A condition for relation cases that do not have identical elements.
					if(arr2[i]==arr1[j]){	   //if the second element of any relation state (first relation state) and the first element of another relation state (second relation state) match,
						if(arr1[j]!=arr2[j]){        //If the second relation state does not have identical elements,
							for(int k=0;k<num;k++){        //one loop as many relations.    
								if(arr1[k]==arr1[i] && arr2[k]==arr2[j]){       //If the first element of the first relation and the second element of the second relation are the same as any relation state (third relation state),
									if(counter3==0){	//The transitive condition is satisfied, and the variables that provide the transitive are assigned to other variables.
										c1=arr1[i];		//The assignment is done once so as not to write all enabling states to the file.
										c2=arr2[i];
										c3=arr2[j];
										counter3++;
									}	
									counter8++;
									counter2++;
									counter18=0;
									
									break;	
								}
								if(arr1[k]==arr1[i] && arr2[k]!=arr2[j]){      //If the transitive situation is not provided,
									if(arr1[k]!=arr2[k]){        //If the relation that does not satisfy does not have equivalent elements,
										c1=arr1[i];          //The transitive condition is not satisfied, and variables that do not satisfy the transitive are assigned to other variables.    
										c2=arr2[i];
										c3=arr2[j];
										counter4++;         //Since no transitive is provided, the counter has been increased.
										counter8=0;
										counter18++;
									}}
								if(arr1[k]==arr1[i] && arr2[k]!=arr2[j]){      //If the transitive situation is not provided,
									if(arr1[k]!=arr2[k]){        //If the relation that does not satisfy does not have equivalent elements,
										c1=arr1[i];          //The transitive condition is not satisfied, and variables that do not satisfy the transitive are assigned to other variables.    
										c2=arr2[i];
										c3=arr2[j];
										counter4++;         //Since no transitive is provided, the counter has been increased.
										counter8=0;
										counter18++;
									}}
								}}}}

			if(j==num-1 && counter4!=0 && counter8==0 && counter18!=0 ){
												 //The end of the cycle has reached and the counter8 counter has not increased so since the transitive state is not provided.
											     //Increased that the counter4 counter Transitive state is not provided.
												 //For these reason,
											     //i'm writing the relation is not valid for transitive and its valid reason to the file.
				file2<<"Transitive: No, "<<"("<<c1<<","<<c3<<") is not found since "<<"("<<c1<<","<<c2<<") and ("<<c2<<","<<c3<<") are found."<<endl;	
				counter19++;
				break;
			}
			}
			if(counter19!=0){
				break;
			}
			if(i==num-1 && counter5==num && counter8==0 && counter18==0){     //If all the relation states are composed of identical elements,
				file2<<"Transitive: Yes,"<<"("<<arr1[0]<<","<<arr2[0]<<")"<<" is found whereas "<<"("<<arr1[0]<<","<<arr2[0]<<")" <<" is found."<<endl;
				break;
			}
			if(i==num-1 && counter8!=0 && counter18==0){        //the end of the cycle is reached and the counter has been increased since the transitive state is provided.
											     //i'm writing the relation is valid for transitive and its valid reason to the file.  
				file2<<"Transitive: Yes, "<<"("<<c1<<","<<c3<<") is found since "<<"("<<c1<<","<<c2<<") and ("<<c2<<","<<c3<<") are found."<<endl;	
			}}}
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