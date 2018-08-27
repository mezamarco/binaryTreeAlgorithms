


#include <iostream>
#include <vector>


//Function protypes

int maximumDepth(Node* root);


//Note that the isBalancedTree function will need a helper function
bool isBalancedTree(Node* root);
int getDepth(Node* current, bool& ans);


bool hasPathSum(Node* root, int sum);
void getAllPathSums(Node* curr, int sum , std::vector<int>& mySumsVect);



int main(){

  return 0;

}






//How far are we form reaching the deepest null node(The node with no children)
int maximumDepth(Node* root){

	if(root == nullptr){
	  return 0;
	}

	return 1 + std::max(maximumDepth(root->left), maximumDepth(root->right));
}





bool isBalancedTree(Node* root){
	
  if(root == nullptr){
  	return 0;
  }

  bool ans = true;
  getDepth(root,ans);
  return ans;
}


//Helper function for the isBalancedTree function
int getDepth(Node* current, bool& ans){
	
	//Base case
	if(current == nullptr){
	  return 0;
	}

	//Get the Depth of the left subtree and the right subtree
	int h1 = getDepth(current->left, ans);
	int h2 = getDepth(current->right, ans);

	//Compare the distance, the distance cannot be greater than one
	if( std::abs(h1 - h2) > 1 ){
		ans = false;
	}

	return 1 + std::max(h1, h2);
}






bool hasPathSum(Node* root, int sum){

	if(root == nullptr){
		return 0;
	}

	//We need a vector of sums, let a helper function populate the vector
	std::vector<int> mySumVect;

	getAllPathSums(root, 0, mySumVect);

	
	//We have populated the vector, now check that if we can find the given sum
	for(int i : mySumVect){
		
		if(i == sum){
		  return true;
		}
	
	}

	return false;
}



void getAllPathSums(Node* curr, int sum , std::vector<int>& mySumsVect){

	//Base case
	if(curr == nullptr){
		return;
	}

	//Add to the local sum
	sum = sum + curr->data;

	if(curr->left == nullptr && curr->right == nullptr){
	  mySumsVect.push_back(sum);
	}

	getAllPathSums( curr->left, sum, mySumsVect);
	getAllPathSums( curr->right, sum, mySumsVect);
}






