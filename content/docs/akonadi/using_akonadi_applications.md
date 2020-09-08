---
title: Using Akonadi in Applications
subtitle: Displaying and modifying data provided by Akonadi
---

This tutorial will guide you through the steps of creating an Akonadi
application, an end user program which displays and manipulates PIM data
provided by Akonadi. 

We will create a simple application allowing a user to "detach" attachments
from e-mails, i.e. save them to disk and remove them from the message. 

## Preparation

We can kick-start the application by using **KAppTemplate**, which can be
found as "KDE template generator" in the development section of the Kickoff,
or by running `kapptemplate` in a terminal window. 

First, we select the KDE Framework C++ in the *Qt* → *Graphical* section of
the program, give our project a name and continue through the following pages
to complete the template creation. 

![KAppTemplate with KDE Framework C++ selected](TutorialAkonadiDetacherTemplate.png)

A look at the generated project top level directory shows us the following files: 

```
CMakeLists.txt
COPYING
COPYING.DOC
Messages.sh
README
doc/
icons/
src/
```

and the following files in sub directory src: 

```
CMakeLists.txt
DetacherSettings.kcfg
DetacherSettings.kcfgc
detacherui.rc
detacherview.cpp
detacherview.h
detacherview.ui
detacherwindow.cpp
detacherwindow.h
main.cpp
org.example.detacher.appdata.xml
org.example.detacher.desktop
settings.ui
```

At this stage it is already possible to compile the application, so we can
already check if our development environment is setup correctly by creating the
build directory and having CMake either generate Makefiles or import the
project in [KDevelop](https://kdevelop.org). 

## Generating Makefiles

From within the generated top level directory: 

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=debugfull ..
````

and run the build using make as usual. 

## Adjusting the main Qt Designer file

Open the file `detacherview.ui` in Qt Designer and remove the example label.
Remove the widget's main layout by clicking on the now empty widget and use
the `Break Layout` menu entry in the Lay out menu. 

Now, from left to right, place two "Tree Views" and one "List Widget"
side-by-side. Select all three boxes in the object inspector docker by holding
<kbd>shift</kbd> and clicking each box with the left mouse button. Use **Layout
Horizontally in a Splitter** in the Lay out menu and then create a main layout
by clicking on their parent widget and using Layout Vertically in the Lay out
menu. 

A preview (*Form* → *Preview*) should now look like this: 

![Preview of the slit layout in Qt Designer](TutorialAkonadiDetacherPreview.png)

Finally, change the object names for the three widgets by right clicking it and
hoosing *Change objectName*. The left widget should be named **folderView**, the
middle one **messageView** and the right one **attachmentList**. 

In order to make it build again, edit the file `detacherview.cpp` and remove the
code from the `settingsChanged\ method. The application should now build again
and be able to run. 

{{< alert title="Note" color="info" >}}
A lot of other code of this generated files is not necessary either, feel free
to do more cleanup yourself.
{{< /alert >}}

## Promoting Views

The [KDE client library for Akonadi](https://api.kde.org/kdepim/akonadi/html/index.html)
has a couple of convenience classes which make our life as application
developers more pleasant. Two of these classes are specialized view widgets,
one for displaying collections and one for displaying items. 

In order to use these widgets instead of ones from Qt we need to use a Qt
Designer feature called "promoting". Right click the left widget and choose
*Promote to*. Then fill the form like shown in the next screenshot. 

![Promote dialog](TutorialAkonadiDetacherPromote.png)

Click add and promote. Repeat the same for the middle widget, this time using
`Akonadi::ItemView` as the class name and `itemview.h` for the header file. 

This change also requires a change in the `CMakeLists.txt` file in the top
level directory and in the one from the source directory. 





