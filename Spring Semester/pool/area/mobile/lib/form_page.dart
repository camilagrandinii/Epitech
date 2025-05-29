import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart'; // Importer Firestore
import 'package:google_fonts/google_fonts.dart'; // Importer Google Fonts
import 'package:bcrypt/bcrypt.dart';

// Page d'inscription
class RegisterPage extends StatefulWidget {
  const RegisterPage({super.key});

  @override
  State<RegisterPage> createState() => _RegisterPageState();
}

class _RegisterPageState extends State<RegisterPage> {
  final _formKey = GlobalKey<FormState>();
  final TextEditingController _emailController = TextEditingController();
  final TextEditingController _passwordController = TextEditingController();
  final TextEditingController _comfirmPasswordController =
      TextEditingController();

  @override
  void dispose() {
    _emailController.dispose();
    _passwordController.dispose();
    _comfirmPasswordController.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      resizeToAvoidBottomInset: false,
      body: Stack(
        children: [
          background(context),
          square(context),
          Positioned(
            top: 50.0,
            left: 0,
            right: 0,
            child: title(context),
          ),
          Positioned(
            top: 165.0, // Position sous le titre
            left: 0,
            right: 0,
            child: searchBar(context), // Ajout de la barre de recherche ici
          ),
          Positioned(
            top: 170.0, // Ajuster en fonction de la barre de recherche
            left: 0,
            right: 0,
            child: squareWorkflow(
                context, 'send a message', 'assets/logo/Discord-Logo.png'),
          ),
        ],
      ),
    );
  }

  Widget background(BuildContext context) {
    return Scaffold(
      body: Container(
        decoration: const BoxDecoration(
          gradient: LinearGradient(
            begin: Alignment.topCenter,
            end: Alignment.bottomCenter,
            colors: [
              Color.fromARGB(255, 158, 99, 182),
              Color(0xFF8E94F2),
              Color(0xFF8E94F2),
            ],
          ),
        ),
      ),
    );
  }

  // Widget principal de la boîte carrée
  Widget square(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.only(top: 100),
      child: Center(
        child: Container(
          width: 366,
          height: 500,
          decoration: BoxDecoration(
            color: const Color.fromARGB(255, 214, 172, 255).withOpacity(0.5),
            borderRadius: BorderRadius.circular(30),
          ),
        ),
      ),
    );
  }

  Widget title(BuildContext context) {
    return AppBar(
      title: Text(
        'Workflows',
        style: GoogleFonts.poppins(
          textStyle: const TextStyle(
            color: Colors.white,
            fontSize: 30,
            fontWeight: FontWeight.w900,
          ),
        ),
      ),
      centerTitle: true,
      backgroundColor: Colors.transparent,
    );
  }

  Widget squareWorkflow(BuildContext context, String text, String path) {
    return Padding(
      padding: const EdgeInsets.only(top: 100),
      child: Center(
        child: Container(
          width: 330,
          height: 65,
          decoration: BoxDecoration(
            color: const Color.fromARGB(255, 214, 172, 255),
            borderRadius: BorderRadius.circular(20),
            boxShadow: [
              BoxShadow(
                color: Colors.black.withOpacity(0.3),
                spreadRadius: 1,
                blurRadius: 3,
                offset: const Offset(0, 4),
              ),
            ],
          ),
          child: Row(
            crossAxisAlignment: CrossAxisAlignment.center,
            mainAxisAlignment: MainAxisAlignment.spaceBetween,
            children: [
              Container(
                width: 1,
                height: 40,
                color: Colors.white,
                margin: const EdgeInsets.only(left: 70.0),
              ),
              Expanded(
                child: Text(
                  text,
                  style: GoogleFonts.poppins(
                    color: Colors.white,
                    fontSize: 12,
                    fontWeight: FontWeight.w500,
                  ),
                  textAlign: TextAlign.center,
                ),
              ),
              Padding(
                padding: const EdgeInsets.only(right: 16.0),
                child: CustomSwitchButton(
                  initialValue: false,
                  activeThumbColor: Colors.white,
                  inactiveThumbColor: Colors.white,
                  activeTrackColor: const Color(0xFF6D71F6),
                  inactiveTrackColor: const Color.fromARGB(255, 255, 255, 255),
                  onChanged: (bool isActive) {
                    print("Switch is now: $isActive");
                  },
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}

// Ajout d'un widget de barre de recherche
// Ajout d'un widget de barre de recherche
Widget searchBar(BuildContext context) {
  return Padding(
    padding: const EdgeInsets.symmetric(horizontal: 20.0, vertical: 10.0),
    child: Row(
      children: [
        Padding(
          padding: const EdgeInsets.only(),
          child: PopupMenuButton<String>(
            icon: Icon(
              Icons.filter_list,
              color: const Color.fromARGB(255, 220, 186, 255),
              size: 30.0,
            ),
            onSelected: (String result) {
              print("Filter selected: $result");
            },
            itemBuilder: (BuildContext context) => <PopupMenuEntry<String>>[
              PopupMenuItem<String>(
                value: 'Alphabetic',
                child: Text(
                  'Alphabetic',
                  style: GoogleFonts.poppins(
                    color: const Color(0xFF6D71F6),
                    fontWeight: FontWeight.w500,
                  ),
                ),
              ),
              PopupMenuItem<String>(
                value: 'Applications',
                child: Text(
                  'Applications',
                  style: GoogleFonts.poppins(
                    color: const Color(0xFF6D71F6),
                    fontWeight: FontWeight.w500,
                  ),
                ),
              ),
            ],
          ),
        ),
        Expanded(
          child: Container(
            height: 45,
            decoration: BoxDecoration(
              color: const Color.fromARGB(255, 255, 255, 255),
              borderRadius: BorderRadius.circular(30),
            ),
            child: Padding(
              padding: const EdgeInsets.symmetric(horizontal: 12.0),
              child: Row(
                children: [
                  Expanded(
                    child: TextField(
                      decoration: InputDecoration(
                        border: InputBorder.none,
                        hintText: "Search...",
                        hintStyle: TextStyle(
                            color: const Color(0xFF6D71F6).withOpacity(0.3)),
                      ),
                      style: const TextStyle(color: const Color(0xFF6D71F6)),
                    ),
                  ),
                  Padding(
                    padding: const EdgeInsets.symmetric(horizontal: 12.0),
                    child: Icon(
                      Icons.search,
                      color: const Color(0xFF757BC8),
                      size: 24.0,
                    ),
                  ),
                ],
              ),
            ),
          ),
        ),
        const SizedBox(width: 10),
        GestureDetector(
          onTap: () {},
          child: Container(
            height: 30,
            width: 30,
            decoration: BoxDecoration(
              color: const Color.fromARGB(0, 149, 117, 205),
              shape: BoxShape.circle,
              border: Border.all(
                color: const Color.fromARGB(255, 214, 172, 255),
                width: 3.0,
              ),
            ),
            child: const Icon(
              Icons.add,
              color: const Color.fromARGB(255, 214, 172, 255),
              size: 24.0,
            ),
          ),
        ),
      ],
    ),
  );
}

class CustomSwitchButton extends StatefulWidget {
  final bool initialValue;
  final Color activeThumbColor;
  final Color inactiveThumbColor;
  final Color activeTrackColor;
  final Color inactiveTrackColor;
  final Function(bool) onChanged;

  const CustomSwitchButton({
    Key? key,
    required this.initialValue,
    required this.activeThumbColor,
    required this.inactiveThumbColor,
    required this.activeTrackColor,
    required this.inactiveTrackColor,
    required this.onChanged,
  }) : super(key: key);

  @override
  _CustomSwitchButtonState createState() => _CustomSwitchButtonState();
}

class _CustomSwitchButtonState extends State<CustomSwitchButton> {
  late bool isActive;

  @override
  void initState() {
    super.initState();
    isActive = widget.initialValue;
  }

  @override
  Widget build(BuildContext context) {
    return Switch(
      value: isActive,
      onChanged: (bool newValue) {
        setState(() {
          isActive = newValue;
        });
        widget.onChanged(newValue);
      },
      activeColor: widget.activeThumbColor,
      activeTrackColor: widget.activeTrackColor,
      inactiveThumbColor: widget.inactiveThumbColor,
      inactiveTrackColor: widget.inactiveTrackColor,
    );
  }
}
