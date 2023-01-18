void Merge(vector<int> &a, int s, int mid, int e){
  int n1 = mid - s + 1;
  int n2 = e - (mid + 1) + 1;
  vector<int> l(n1);
  vector<int> r(n2);
  for(int i=0; i<n1; i++)
    l[i] = a[s + i];
  for(int i=0; i<n2; i++)
    r[i] = a[mid + 1 + i];
  int i = 0;
  int j = 0;
  int k = s;
  while(i<n1 && j<n2){
    if(l[i] < r[j]){
      a[k] = l[i];
      i++;
    }
    else{
      a[k] = r[j];
      j++;
    }
    k++;
  }
  while(i < n1){
    a[k] = l[i];
    i++;
    k++;
  }
  while(j < n2){
    a[k] = r[j];
    j++;
    k++;
  }
}

void mergeSort(vector<int> &a, int s, int e){
  if(s < e){
    int mid = (s + e)/2;
    mergeSort(a, s, mid);
    mergeSort(a, mid + 1, e);
    Merge(a, s, mid, e);
  }
}
