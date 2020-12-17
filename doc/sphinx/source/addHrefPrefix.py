import glob
import re
import shutil

prefix = "/doc/"

def editHrefs(html_file):
  patterns = [
    (r'href="([a-zA-Z\-]*\.html)"', r'href="' + prefix + r'\1"'),
    (r'href="_', r'href="' + prefix + '_')
  ]

  html_file_mod = html_file + ".tmp"

  fp_new = open(html_file_mod, "w")

  with open(html_file) as fp:
    line = fp.readline()
    cnt = 1
    while line:
      noMatch = True
      for (a,b) in patterns:
        c = re.compile(a)
        if c.search(line):
          s = re.sub(a, b, line)
          fp_new.write(s)
          noMatch = False

      if noMatch:
        fp_new.write(line)
      line = fp.readline()
      cnt += 1

  shutil.move(html_file_mod, html_file)

# Go through the built HTML files
html_files = glob.glob("../buildRootMod/html/*.html")

for html_file in html_files:
  editHrefs(html_file)