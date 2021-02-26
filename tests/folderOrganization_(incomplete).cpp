#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minFolders' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER cssFiles
 *  2. INTEGER jsFiles
 *  3. INTEGER readMeFiles
 *  4. INTEGER capacity
 */
#include <vector>
#define THREESHOLD 1

struct Folder {
  int n_readme = 0;
  int n_css = 0;
  int n_js = 0;
  int capacity = 0;

  Folder(int a = 0, int b = 0, int c = 0, int d = 0)
      :

        bool is_valid() {
    return n_readme <= 0 && abs(n_css - n_js) == 0 &&
           n_readme + n_css + n_js <= capacity;
  }

  void addCurrent(int i) {
    if (i == 1) {
      addCSS();
    }
    if (i == 2) {
      addJS();
    }
  }
  void remCurrent(int i) {
    if (i == 1) {
      remCSS();
    }
    if (i == 2) {
      remJS();
    }
  }

  void addCSS() { ++n_css; }
  void addJS() { ++n_js; }
  void remCSS() { --n_css; }
  void remJS() { --n_js; }
};

// types: 0 = README, 1 = CSS, 2 = JS

static struct NextType {
  static int who_is_next(int current) {
    if (current + 1 > 2) {
      return 0;
    }
    return current + 1;
  }

  static int readme_allocated;
  static int css_allocated;
  static int js_allocated;

  int sum() { return readme_allocated + css_allocated + js_allocated; }

} NextIterator;

int NextType::readme_allocated = 0;
int NextType::css_allocated = 0;
int NextType::js_allocated = 0;

int minFolders(int cssFiles, int jsFiles, int readMeFiles, int capacity) {
  int ret = 0;
  bool finish = false;
  int hasReadme = false;
  int n_readme = readMeFiles;
  int n_css = cssFiles;
  int n_js = jsFiles;
  auto a = Folder{1, 0, 0, capacity};
  vector<Folder> folders(readMeFiles, a);

  auto it = folders.begin();
  int current_type;
  cssFiles > jsFiles ? current_type = cssFiles : current_type = jsFiles;
  NextIterator.readme_allocated = readMeFiles;

  while (!finish) {
    it->addCurrent(current_type);
    if (!it->is_valid()) {
      it->remCurrent(current_type);
    } else {
      if (current_type == 1) {
        ++NextIterator.css_allocated;
      }
      if (current_type == 2) {
        ++NextIterator.js_allocated;
      }
      if (NextIterator.sum() == cssFiles + jsFiles + readMeFiles) {
        finish = true;
      }
    }
    current_type = NextIterator.who_is_next(current_type);
  }
  return 1;
}

int main()