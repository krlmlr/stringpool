<!-- README.md is generated from README.Rmd. Please edit that file -->

# stringpool

<!-- badges: start -->

[![Lifecycle: experimental](https://img.shields.io/badge/lifecycle-experimental-orange.svg)](https://lifecycle.r-lib.org/articles/stages.html#experimental)

<!-- badges: end -->

The goal of stringpool is to help developers understand R’s global string pool.

## Installation

You can install the development version of stringpool like so:

<pre class='chroma'>
<span><span class='nf'>pak</span><span class='nf'>::</span><span class='nf'><a href='http://pak.r-lib.org/reference/pak.html'>pak</a></span><span class='o'>(</span><span class='s'>"krlmlr/stringpool"</span><span class='o'>)</span></span></pre>

## Example

<pre class='chroma'>
<span><span class='kr'><a href='https://rdrr.io/r/base/library.html'>library</a></span><span class='o'>(</span><span class='nv'><a href='https://github.com/krlmlr/duckplyr'>stringpool</a></span><span class='o'>)</span></span></pre>

Use `stringpool()` to get all strings currently known to R as a character vector:

<pre class='chroma'>
<span><span class='nf'><a href='https://rdrr.io/r/base/lapply.html'>lapply</a></span><span class='o'>(</span><span class='nf'><a href='https://rdrr.io/r/utils/head.html'>head</a></span><span class='o'>(</span><span class='nf'>stringpool</span><span class='o'>(</span><span class='o'>)</span><span class='o'>)</span>, <span class='nv'>charToRaw</span><span class='o'>)</span></span>
<span><span class='c'>#&gt; [[1]]</span></span>
<span><span class='c'>#&gt; raw(0)</span></span>
<span><span class='c'>#&gt; </span></span>
<span><span class='c'>#&gt; [[2]]</span></span>
<span><span class='c'>#&gt; [1] e3 82 99</span></span>
<span><span class='c'>#&gt; </span></span>
<span><span class='c'>#&gt; [[3]]</span></span>
<span><span class='c'>#&gt; [1] e3 80 aa</span></span>
<span><span class='c'>#&gt; </span></span>
<span><span class='c'>#&gt; [[4]]</span></span>
<span><span class='c'>#&gt; [1] e3 80 ae</span></span>
<span><span class='c'>#&gt; </span></span>
<span><span class='c'>#&gt; [[5]]</span></span>
<span><span class='c'>#&gt; [1] 09</span></span>
<span><span class='c'>#&gt; </span></span>
<span><span class='c'>#&gt; [[6]]</span></span>
<span><span class='c'>#&gt; [1] 0a</span></span></pre>

If you need to understand the evolution of the global string table, writing to disk is a good idea.

<pre class='chroma'>
<span><span class='nv'>path1</span> <span class='o'>&lt;-</span> <span class='nf'><a href='https://rdrr.io/r/base/tempfile.html'>tempfile</a></span><span class='o'>(</span>fileext <span class='o'>=</span> <span class='s'>".txt"</span><span class='o'>)</span></span>
<span><span class='nf'><a href='https://rdrr.io/pkg/stringpool/man/write_stringpool.html'>write_stringpool</a></span><span class='o'>(</span><span class='nv'>path1</span>, sep <span class='o'>=</span> <span class='s'>"=====\n"</span><span class='o'>)</span></span>
<span><span class='nf'>fs</span><span class='nf'>::</span><span class='nf'><a href='https://fs.r-lib.org/reference/file_info.html'>file_info</a></span><span class='o'>(</span><span class='nv'>path1</span><span class='o'>)</span></span>
<span><span class='c'>#&gt; <span style='color: #555555;'># A tibble: 1 × 18</span></span></span>
<span><span class='c'>#&gt;   <span style='font-weight: bold;'>path</span>             <span style='font-weight: bold;'>type</span>   <span style='font-weight: bold;'>size</span> <span style='font-weight: bold;'>permiss…¹</span> <span style='font-weight: bold;'>modification_time</span>   <span style='font-weight: bold;'>user</span>  <span style='font-weight: bold;'>group</span> <span style='font-weight: bold;'>devic…²</span></span></span>
<span><span class='c'>#&gt;   <span style='color: #555555; font-style: italic;'>&lt;fs::path&gt;</span>       <span style='color: #555555; font-style: italic;'>&lt;fct&gt;</span> <span style='color: #555555; font-style: italic;'>&lt;fs:&gt;</span> <span style='color: #555555; font-style: italic;'>&lt;fs::per&gt;</span> <span style='color: #555555; font-style: italic;'>&lt;dttm&gt;</span>              <span style='color: #555555; font-style: italic;'>&lt;chr&gt;</span> <span style='color: #555555; font-style: italic;'>&lt;chr&gt;</span>   <span style='color: #555555; font-style: italic;'>&lt;dbl&gt;</span></span></span>
<span><span class='c'>#&gt; <span style='color: #555555;'>1</span> …87b1be475a8.txt file   390K rw-r--r-- 2023-04-08 <span style='color: #555555;'>13:29:30</span> kiri… staff  1.68<span style='color: #555555;'>e</span>7</span></span>
<span><span class='c'>#&gt; <span style='color: #555555;'># ℹ abbreviated names: ¹​permissions, ²​device_id</span></span></span>
<span><span class='c'>#&gt; <span style='color: #555555;'># ℹ 10 more variables: </span><span style='color: #555555; font-weight: bold;'>hard_links</span><span style='color: #555555;'> &lt;dbl&gt;, </span><span style='color: #555555; font-weight: bold;'>special_device_id</span><span style='color: #555555;'> &lt;dbl&gt;, </span><span style='color: #555555; font-weight: bold;'>inode</span><span style='color: #555555;'> &lt;dbl&gt;,</span></span></span>
<span><span class='c'>#&gt; <span style='color: #555555;'>#   </span><span style='color: #555555; font-weight: bold;'>block_size</span><span style='color: #555555;'> &lt;dbl&gt;, </span><span style='color: #555555; font-weight: bold;'>blocks</span><span style='color: #555555;'> &lt;dbl&gt;, </span><span style='color: #555555; font-weight: bold;'>flags</span><span style='color: #555555;'> &lt;int&gt;, </span><span style='color: #555555; font-weight: bold;'>generation</span><span style='color: #555555;'> &lt;dbl&gt;,</span></span></span>
<span><span class='c'>#&gt; <span style='color: #555555;'>#   </span><span style='color: #555555; font-weight: bold;'>access_time</span><span style='color: #555555;'> &lt;dttm&gt;, </span><span style='color: #555555; font-weight: bold;'>change_time</span><span style='color: #555555;'> &lt;dttm&gt;, </span><span style='color: #555555; font-weight: bold;'>birth_time</span><span style='color: #555555;'> &lt;dttm&gt;</span></span></span>
<span></span>
<span><span class='nv'>path2</span> <span class='o'>&lt;-</span> <span class='nf'><a href='https://rdrr.io/r/base/tempfile.html'>tempfile</a></span><span class='o'>(</span>fileext <span class='o'>=</span> <span class='s'>".txt"</span><span class='o'>)</span></span>
<span><span class='nf'><a href='https://rdrr.io/pkg/stringpool/man/write_stringpool.html'>write_stringpool</a></span><span class='o'>(</span><span class='nv'>path2</span>, sep <span class='o'>=</span> <span class='s'>"=====\n"</span><span class='o'>)</span></span>
<span><span class='nf'>fs</span><span class='nf'>::</span><span class='nf'><a href='https://fs.r-lib.org/reference/file_info.html'>file_info</a></span><span class='o'>(</span><span class='nv'>path2</span><span class='o'>)</span></span>
<span><span class='c'>#&gt; <span style='color: #555555;'># A tibble: 1 × 18</span></span></span>
<span><span class='c'>#&gt;   <span style='font-weight: bold;'>path</span>             <span style='font-weight: bold;'>type</span>   <span style='font-weight: bold;'>size</span> <span style='font-weight: bold;'>permiss…¹</span> <span style='font-weight: bold;'>modification_time</span>   <span style='font-weight: bold;'>user</span>  <span style='font-weight: bold;'>group</span> <span style='font-weight: bold;'>devic…²</span></span></span>
<span><span class='c'>#&gt;   <span style='color: #555555; font-style: italic;'>&lt;fs::path&gt;</span>       <span style='color: #555555; font-style: italic;'>&lt;fct&gt;</span> <span style='color: #555555; font-style: italic;'>&lt;fs:&gt;</span> <span style='color: #555555; font-style: italic;'>&lt;fs::per&gt;</span> <span style='color: #555555; font-style: italic;'>&lt;dttm&gt;</span>              <span style='color: #555555; font-style: italic;'>&lt;chr&gt;</span> <span style='color: #555555; font-style: italic;'>&lt;chr&gt;</span>   <span style='color: #555555; font-style: italic;'>&lt;dbl&gt;</span></span></span>
<span><span class='c'>#&gt; <span style='color: #555555;'>1</span> …87b33e876e6.txt file   520K rw-r--r-- 2023-04-08 <span style='color: #555555;'>13:29:31</span> kiri… staff  1.68<span style='color: #555555;'>e</span>7</span></span>
<span><span class='c'>#&gt; <span style='color: #555555;'># ℹ abbreviated names: ¹​permissions, ²​device_id</span></span></span>
<span><span class='c'>#&gt; <span style='color: #555555;'># ℹ 10 more variables: </span><span style='color: #555555; font-weight: bold;'>hard_links</span><span style='color: #555555;'> &lt;dbl&gt;, </span><span style='color: #555555; font-weight: bold;'>special_device_id</span><span style='color: #555555;'> &lt;dbl&gt;, </span><span style='color: #555555; font-weight: bold;'>inode</span><span style='color: #555555;'> &lt;dbl&gt;,</span></span></span>
<span><span class='c'>#&gt; <span style='color: #555555;'>#   </span><span style='color: #555555; font-weight: bold;'>block_size</span><span style='color: #555555;'> &lt;dbl&gt;, </span><span style='color: #555555; font-weight: bold;'>blocks</span><span style='color: #555555;'> &lt;dbl&gt;, </span><span style='color: #555555; font-weight: bold;'>flags</span><span style='color: #555555;'> &lt;int&gt;, </span><span style='color: #555555; font-weight: bold;'>generation</span><span style='color: #555555;'> &lt;dbl&gt;,</span></span></span>
<span><span class='c'>#&gt; <span style='color: #555555;'>#   </span><span style='color: #555555; font-weight: bold;'>access_time</span><span style='color: #555555;'> &lt;dttm&gt;, </span><span style='color: #555555; font-weight: bold;'>change_time</span><span style='color: #555555;'> &lt;dttm&gt;, </span><span style='color: #555555; font-weight: bold;'>birth_time</span><span style='color: #555555;'> &lt;dttm&gt;</span></span></span></pre>
