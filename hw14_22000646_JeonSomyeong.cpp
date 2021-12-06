#include <iostream>
#define HSIZE 100

using namespace std;

class s_record
{
public:
   string s_id;  // 학번 (Key)
   string name;  // 성명
   double score; // 점수
   s_record()
   {
      s_id = "";
      name = "";
      score = 0;
   }
   s_record(string s1, string s2, double n)
   {
      s_id = s1;
      name = s2;
      score = n;
   }
};

class my_heap
{
   s_record h[HSIZE];
   int csize; // the number of s_records
public:
   my_heap();
   my_heap(s_record a[], int num);
   int h_size();
   void insert_heap(s_record t);
   s_record delete_heap();
   bool heap_full();
   bool heap_empty();
   double score_sum();
   double score_average();
   void adjust(int t_root);
   int node_delete_by_name(string tname);
};
my_heap::my_heap()
{
   csize = 0;
}
my_heap::my_heap(s_record a[], int num)
{
   s_record temp;
   csize = 0;
   for (int i = 0; i < num; i++)
   {
      insert_heap(a[i]);
   }
}
bool my_heap::heap_empty()
{
   if (csize == 0)
      return true;
   else
      return false;
}
bool my_heap::heap_full()
{
   if (csize >= HSIZE - 1)
      return true;
   else
      return false;
}
int my_heap::h_size()
{
   return csize;
}
void my_heap::insert_heap(s_record t)
{
   int k;
   csize++;
   k = csize;
   while ((k != 1) && (t.score > h[k / 2].score))
   {
      h[k] = h[k / 2];
      k /= 2;
   }
   h[k] = t;
}
s_record my_heap::delete_heap()
{
   s_record t;
   s_record tmp;
   int parent, child;
   t = h[1];       // for return value
   tmp = h[csize]; // 끝원소
   csize--;
   parent = 1; // root
   child = 2;  // root의 left child
   while (child <= csize)
   {
      if ((child < csize) && (h[child].score < h[child + 1].score))
         child++; // right child를 선택
      if (tmp.score >= h[child].score)
         break;
      h[parent] = h[child];
      parent = child; // 한단계 아래로
      child *= 2;
   }
   h[parent] = tmp;
   return t;
}
void adjust(s_record a[], int troot, int size)
{
   double tmpkey;
   int child;
   s_record tmp;
   tmp = a[troot];
   tmpkey = a[troot].score;
   child = 2 * troot;
   while (child <= size)
   {
      if ((child < size) && (a[child].score < a[child + 1].score))
         child++;
      if (tmpkey > a[child].score)
         break;
      else
      {
         a[child / 2] = a[child];
         child *= 2;
      }
   }
   a[child / 2] = tmp;
}
void insertion_sort(s_record s_list[], int n)
{
   for (int i = 1; i < n; i++)
   {
      s_record temp = s_list[i];
      int j = i - 1;
      while ((j >= 0 && s_list[j].s_id > temp.s_id))
      {
         s_list[j + 1] = s_list[j];
         j--;
      }
      s_list[j + 1] = temp;
   }
}
void bubble_sort(s_record s_list[], int n)
{
   s_record temp;

   for (int i = n - 1; i >= 1; i--)
   {
      for (int j = 0; j < i; j++)
      {
         if (s_list[j + 1].s_id < s_list[j].s_id)
         {
            temp = s_list[j + 1];
            s_list[j + 1] = s_list[j];
            s_list[j] = temp;
         }
      }
   }
}
void selection_sort(s_record s_list[], int n)
{
   s_record temp;
   for (int i = 0; i < n; i++)
   {
      int min_i = i;
      for (int j = i + 1; j < n; j++)
      {
         if (s_list[j].s_id < s_list[min_i].s_id)
            min_i = j;
         temp = s_list[i];
         s_list[i] = s_list[min_i];
         s_list[min_i] = temp;
      }
   }
}
void quick_sort(s_record s_list[], int left, int right)
{
   s_record pivot, temp;
   int i, j;
   if (left >= right)
      return;
   i = left;
   j = right + 1;
   pivot = s_list[left];
   do
   {
      do
      {
         i++;
      } while ((i <= right) && (s_list[i].s_id < pivot.s_id));
      do
      {
         j--;
      } while (s_list[j].s_id > pivot.s_id);
      if (i < j)
         swap(s_list[i], s_list[j]);
   } while (i < j);
   swap(s_list[left], s_list[j]);
   quick_sort(s_list, left, j - 1);
   quick_sort(s_list, j + 1, right);
}
void merge(s_record a[], s_record b[], int n1, int n2, int n3, int n4)
{
   int i, j, k, t;
   i = n1;
   j = n3;
   k = n1;
   while ((i <= n2) && (j <= n4))
   {
      if (a[i].s_id <= a[j].s_id)
         b[k++] = a[i++];
      else
         b[k++] = a[j++];
   }
   if (i > n2)
   {
      for (t = j; t <= n4; t++)
         b[t] = a[t];
   }
   else
      for (t = i; t <= n2; t++)
         b[k + t - i] = a[t];
}
void merge_pass(s_record a[], s_record b[], int n, int s)
{
   int i, j;
   for (i = 0; i < (n - 2 * s + 1); i += 2 * s)
      merge(a, b, i, i + s - 1, i + s, i + 2 * s - 1);
   if (i + s <= n)
      merge(a, b, i, i + s - 1, i + s, n);
   else
      for (j = i; j <= n; j++)
         b[j] = a[j];
}
void merge_sort(s_record s_list[], int n)
{
   int s = 1;
   s_record b[HSIZE];
   while (s < n)
   {
      merge_pass(s_list, b, n - 1, s);
      s *= 2;
      merge_pass(b, s_list, n - 1, s);
      s *= 2;
   }
}
void heap_sort(s_record s_list[], int n)
{
   int i;
   s_record temp;
   int size = n - 1;
   for (i = (size - 1) / 2; i >= 0; i--)
      adjust(s_list, i, size);
   for (i = size - 1; i >= 0; i--)
   {
      temp = s_list[0];
      s_list[0] = s_list[i + 1];
      s_list[i + 1] = temp;
      adjust(s_list, 0, i);
   }
}
void show_thelist(s_record s_list[], int n)
{
   for (int i = 0; i < n; i++)
   {
      cout << s_list[i].s_id << "  :  ";
      cout << s_list[i].name << "  :  ";
      cout << s_list[i].score << endl;
   }
}

int main()
{
   // s_record s_list[12] = {{"21900013", "Kim ", 6.5}, {"21900136", "Lee ", 8.8}, {"21900333", "Park", 9.2}, {"21800442", "Choi", 7.1}, {"21900375", "Ryu ", 5.4}, {"21700248", "Cho ", 6.3}, {"21700302", "Jung", 8.3}, {"21800255", "Han ", 6.9}, {"21800369", "Kang", 6.3}, {"21900401", "Yang", 9.1}, {"21800123", "Moon", 8.1}, {"21700678", "Seo ", 7.9}};
   s_record s_list[12] = {s_record("21900013", "Kim ", 6.5), s_record("21900136", "Lee ", 8.8), s_record("21900333", "Park", 9.2), s_record("21800442", "Choi", 7.1), s_record("21900375", "Ryu ", 5.4), s_record("21700248", "Cho ", 6.3), s_record("21700302", "Jung", 8.3), s_record("21800255", "Han ", 6.9), s_record("21800369", "Kang", 6.3), s_record("21900401", "Yang", 9.1), s_record("21800123", "Moon", 8.1), s_record("21700678", "Seo ", 7.9)};
   int n = 12;

   // insertion_sort(s_list, n);
   // bubble_sort(s_list, n);
   // selection_sort(s_list, n);
   // quick_sort(s_list, 0, n-1);
   // merge_sort(s_list, n);
   heap_sort(s_list, n);
   cout << "<The result of the sorting> " << endl;
   show_thelist(s_list, n);

   return 0;
}