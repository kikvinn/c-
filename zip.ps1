$sourceFile1 = "C:\Users\kikvinn\Desktop\Project\c-\rational\rational.cpp"
$sourceFile2 = "C:\Users\kikvinn\Desktop\Project\c-\rational\rational.h"
$sourcefolder = "C:\Users\kikvinn\Desktop\Project\c-\rational\*"

$outputZipPath = "C:\Users\kikvinn\Desktop\Project\c-/output.zip"

Compress-Archive -Path $sourcefolder -DestinationPath $outputZipPath -Force
